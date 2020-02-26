#ifndef XMLPARSER_H
#define XMLPARSER_H
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QString>

#ifdef QT_DEBUG
#include <QDebug>
#endif

namespace cloudrain {
namespace utility {
namespace parser {

    class XmlParser : public QObject
    {
        private :
            QString xmlFilePath;

        protected:
        public :
            explicit XmlParser(QObject *parent = nullptr);
            explicit XmlParser(const QString &path, QObject *parent = nullptr);
            virtual ~XmlParser() noexcept;
    };
}
}
}
#endif // XMLPARSER_H
