#ifndef FILEEXPORTER_H
#define FILEEXPORTER_H

#include <QString>
#include <QFile>
#include <string>

class FileExporter
{
public:
    virtual ~FileExporter() = default;

    // Это контракт. Метод который описывает что и с чем делать. но не описывает как.
    // Говорят так соответствует правильному подходу к повторному использованию кода (DRY — Don't Repeat Yourself).
    virtual bool exportMenu(const std::string* menu,
                            const QString& dayName,
                            const QString& filePath) = 0;

protected:

    FileExporter() = default;


    bool openFile(const QString& filePath) {
        filename.setFileName(filePath);
        return filename.open(QIODevice::WriteOnly | QIODevice::Text);
    }

    void writeToFile(const QByteArray& data) {
        filename.write(data);
    }
    // Разные методы а точнее перегрузка метода
    void writeToFile(const QString& text) {
        filename.write(text.toUtf8());
    }

    bool closeFile() {
        filename.close();
        return true;
    }

    bool isOpen() const {
        return filename.isOpen();
    }

    // Сам файл — защищённый, доступен наследникам
    QFile filename;

private:

    FileExporter(const FileExporter&) = delete;
    FileExporter& operator=(const FileExporter&) = delete;
};

#endif // FILEEXPORTER_H
