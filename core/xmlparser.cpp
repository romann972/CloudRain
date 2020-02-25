#include "xmlparser.h"

cloudrain::utility::parser::XmlParser::XmlParser(QObject *parent)
    : QObject(parent)
{

}

cloudrain::utility::parser::XmlParser::XmlParser(const QString &path, QObject *parent)
    : QObject(parent), xmlFilePath(path)
{

}

cloudrain::utility::parser::XmlParser::~XmlParser() noexcept
{

}

