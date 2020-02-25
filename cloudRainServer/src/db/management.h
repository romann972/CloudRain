#ifndef MANAGEMENT_H
#define MANAGEMENT_H
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>

#ifdef QT_DEBUG
#include <QDebug>
#endif

#include "schema.h"

namespace cloudrain {
namespace db {

    class Management
    {
        private :
            static QSqlDatabase db;
            static const QString name;
            static const QString hostName;
            static const QString path;
            static QSqlQuery query;

        public :
            Management() = delete;
            static bool connect();
            static bool disconnect();
            static void createTable();
            static void deleteTable(QString name);
            static void insertIntoTable(QString name, QString values, QString table);
            static void SelectTable(QString name, QString table, QString where="1=1");
            static void updateTable(QString name, QString set, QString where="1=1");
            ~Management();
    };

}
}

#endif // MANAGEMENT_H
