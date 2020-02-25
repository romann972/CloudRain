#ifndef JSONPARSER_H
#define JSONPARSER_H
#include <QObject>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

#ifdef QT_DEBUG
#include <QDebug>
#endif

namespace cloudrain::utility::parser {

    class JsonParser : public QObject
    {
        private :
            QString jsonFilePath;
            QString testJson;

        protected :
        public:
            explicit JsonParser(QObject *parent = nullptr);
            explicit JsonParser(const QString jsonFilePath, QObject *parent = nullptr);
            virtual ~JsonParser() noexcept;
    };

}
#endif // JSONPARSER_H
