#ifndef JSONEXPORTER_H
#define JSONEXPORTER_H

#include "fileexporter.h"  


class JsonExporter : public FileExporter
{
public:
    // Переопределяем виртуальный метод
    bool exportMenu(const std::string* menu,
                    const QString& dayName,
                    const QString& filePath) override;
};

#endif // JSONEXPORTER_H