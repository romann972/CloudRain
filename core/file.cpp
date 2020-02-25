#include "file.h"

cloudrain::utility::io::File::File(QObject *parent)
    : QObject(parent)
{

}

cloudrain::utility::io::File::File(const QString path, QObject *parent)
    : QObject(parent), path(path)
{

}

QString cloudrain::utility::io::File::readAll(const QString path)
{
    this->setPath(path);
    return readAll();
}

QString cloudrain::utility::io::File::readAll()
{
    QFile file(path);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        QString data = in.readAll();
        file.close();
        return data;
    } else{
        return "";
    }
}

bool cloudrain::utility::io::File::write(const QString data) const
{
    QFile file(path);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        file.write(data.toUtf8());
        file.close();
        return true;
    } else{
        return false;
    }
}

bool cloudrain::utility::io::File::isExentension(const QString extension)
{
    QFileInfo fileInfo(path);
    if(fileInfo.completeSuffix() == extension)
    {
        return true;
    } else{
        return false;
    }
}

QString cloudrain::utility::io::File::getPath() const
{
    return this->path;
}

void cloudrain::utility::io::File::setPath(const QString path)
{
    this->path = path;
}

cloudrain::utility::io::File::~File() noexcept
{

}
