#include "wordexporter.h"
#include "miniz.h"
#include "fileexporter.h"

bool WordExporter::exportMenu(const std::string* menu,
                              const QString& dayName,
                              const QString& filePath)
{
    // 1. Генерируем содержимое трёх XML-файлов (в UTF-8)
    QByteArray documentXml = generateDocumentXml(menu, dayName).toUtf8();
    QByteArray contentTypesXml = generateContentTypesXml().toUtf8();
    QByteArray relsXml = generateRelsXml().toUtf8();

    // 2. Инициализируем ZIP-архив через miniz
    mz_zip_archive zip_archive;
    memset(&zip_archive, 0, sizeof(zip_archive));

    // Открываем файл для записи ZIP
    if (!mz_zip_writer_init_file(&zip_archive, filePath.toUtf8().constData(), 0))
        return false;

    // 3. Добавляем файлы в архив (важны пути внутри ZIP!)
    //    Путь "word/document.xml" — это путь ВНУТРИ архива, не на диске!
    if (!mz_zip_writer_add_mem(&zip_archive, "word/document.xml",
                               documentXml.constData(), documentXml.size(), MZ_DEFAULT_COMPRESSION)) {
        mz_zip_writer_end(&zip_archive);
        return false;
    }

    if (!mz_zip_writer_add_mem(&zip_archive, "[Content_Types].xml",
                               contentTypesXml.constData(), contentTypesXml.size(), MZ_DEFAULT_COMPRESSION)) {
        mz_zip_writer_end(&zip_archive);
        return false;
    }

    if (!mz_zip_writer_add_mem(&zip_archive, "_rels/.rels",
                               relsXml.constData(), relsXml.size(), MZ_DEFAULT_COMPRESSION)) {
        mz_zip_writer_end(&zip_archive);
        return false;
    }

    // 4. Завершаем архив (записывает центральный каталог)
    if (!mz_zip_writer_finalize_archive(&zip_archive)) {
        mz_zip_writer_end(&zip_archive);
        return false;
    }

    // 5. Освобождаем ресурсы
    mz_zip_writer_end(&zip_archive);

    return true;  // Успех!
}

QString WordExporter::generateDocumentXml(const std::string* menu, const QString& dayName)
{
    // 1. Начало XML-документа (закрытая raw string)
    QString xml = R"(<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<w:document xmlns:w="http://schemas.openxmlformats.org/wordprocessingml/2006/main">
<w:body>)";

    // 2. Заголовок: день недели
    xml += QString("<w:p><w:r><w:t xml:space=\"preserve\">Menu for %1</w:t></w:r></w:p>")
        .arg(dayName);

    // 3. Цикл по 4 блюдам
    for (int i = 0; i < 4; ++i) {
        // Конвертация + экранирование спецсимволов XML
        QString dish = QString::fromStdString(menu[i]);
        dish.replace("&", "&amp;")
            .replace("<", "&lt;")
            .replace(">", "&gt;")
            .replace("\"", "&quot;");

        xml += QString("<w:p><w:r><w:t xml:space=\"preserve\">%1. %2</w:t></w:r></w:p>")
            .arg(i + 1)
            .arg(dish);
    }

    // 4. Закрытие XML (тоже закрытая raw string)
    xml += R"(</w:body>
</w:document>)";

    // 5. Возвращаем результат
    return xml;
}

QString WordExporter::generateContentTypesXml()
{
    // При передаче в miniz: следует использовать .toUtf8(), а не toStdString()!
    const QString content_type = R"(<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<Types xmlns="http://schemas.openxmlformats.org/package/2006/content-types">
  <Default Extension="rels" ContentType="application/vnd.openxmlformats-package.relationships+xml"/>
  <Default Extension="xml" ContentType="application/xml"/>
  <Override PartName="/word/document.xml" ContentType="application/vnd.openxmlformats-officedocument.wordprocessingml.document.main+xml"/>
</Types>)";

    return content_type.trimmed(); // Убирает лишние пробелы в начале/конце
}

QString WordExporter::generateRelsXml()
{
    const QString root_rels = R"(<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<Relationships xmlns="http://schemas.openxmlformats.org/package/2006/relationships">
  <Relationship Id="rId1" Type="http://schemas.openxmlformats.org/officeDocument/2006/relationships/officeDocument" Target="word/document.xml"/>
</Relationships>)";

    return root_rels.trimmed();
}
