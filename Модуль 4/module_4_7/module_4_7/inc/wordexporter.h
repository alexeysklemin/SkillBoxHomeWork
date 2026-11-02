// wordexporter.h
#ifndef WORDEXPORTER_H
#define WORDEXPORTER_H

#include <QString>
#include "fileexporter.h"

class WordExporter : public FileExporter
{
public:
    bool exportMenu(const std::string* menu,
                    const QString& dayName,
                    const QString& filePath) override;
    
private:
    // Свои методы! Поэтому объявляем в хедере
    QString generateDocumentXml(const std::string* menu, const QString& dayName);
    QString generateContentTypesXml();
    QString generateRelsXml();
};

#endif