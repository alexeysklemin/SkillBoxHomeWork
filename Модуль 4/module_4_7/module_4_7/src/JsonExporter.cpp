#include "FileExporter.h"
#include "JsonExporter.h"
#include "Logger.h"

#include "jsonexporter.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

bool JsonExporter::exportMenu(const std::string* menu,
                               const QString& dayName,
                               const QString& filePath)
{
    // 1. Открываем файл через базовый класс
    if (!openFile(filePath)) {
        return false;  // Не удалось открыть
    }
    
    // 2. Создаём JSON, корень корней
    QJsonObject root;
    root["day"] = dayName;
    
    QJsonArray dishes;
    for (int i = 0; i < 4; ++i) {
        dishes.append(QString::fromStdString(menu[i]));
    }
    root["menu"] = dishes; //Корень меню
    
    // 3. Пишем через базовый класс
    writeToFile(QJsonDocument(root).toJson(QJsonDocument::Indented));
    
    // 4. Закрываем через базовый класс
    closeFile();
    
    return true;
}