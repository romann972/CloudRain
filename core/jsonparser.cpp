#include "jsonparser.h"

cloudrain::utility::parser::JsonParser::JsonParser(QObject *parent)
    : QObject(parent)
{
    testJson = "config{\"name\": \"auzou\",\"id\": str,\"ip\": \"192.168.16.12\"}";
    auto jsonDoc = QJsonDocument::fromJson(testJson.toUtf8());
    QJsonObject jsonObj = jsonDoc.object();

}

cloudrain::utility::parser::JsonParser::JsonParser(const QString jsonFilePath, QObject *parent)
    : QObject(parent), jsonFilePath(jsonFilePath)
{

}

cloudrain::utility::parser::JsonParser::~JsonParser() noexcept
{

}
