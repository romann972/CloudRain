#ifndef FILE_H
#define FILE_H
#include <QObject>
#include <QFile>
#include <QFileInfo>

#ifdef QT_DEBUG
#include <QDebug>
#endif

namespace cloudrain::utility::io {
    class File : public QObject
    {
        private :
            QString path;

        protected :

        public :
            explicit File(QObject *parent = nullptr);
            explicit File(const QString path, QObject *parent = nullptr);
            QString readAll(const QString path);
            QString readAll();
            bool write(const QString data) const;
            bool isExentension(const QString extension);

            QString getPath() const;

            void setPath(const QString path);

            virtual ~File() noexcept;
    };
}

#endif // FILE_H
