#include "management.h"

const QString cloudrain::db::Management::name = "QSQLITE";
QSqlDatabase cloudrain::db::Management::db = QSqlDatabase::addDatabase(name);
const QString cloudrain::db::Management::hostName = cloudrain::gui::global::db::SQLITE_PATH;
const QString cloudrain::db::Management::path = cloudrain::gui::global::db::SQLITE_NAME;
QSqlQuery cloudrain::db::Management::query = QSqlQuery(cloudrain::db::Management::db);


bool cloudrain::db::Management::connect()
{
    if(Management::db.isOpen() == false)
    {
        Management::db.setDatabaseName(Management::path);
        Management::db.setHostName(Management::hostName);
        Management::db.open();
        Management::query.prepare("PRAGMA encoding=\"UTF-8\";");
        Management::query.exec();

        return true;
    } else if(Management::db.isOpenError()){
        return false;
    } else{
        return true;
    }
}

bool cloudrain::db::Management::disconnect()
{
    if(Management::db.isOpen() == true)
    {
        Management::db.close();

        return true;
    } else{
        return false;
    }
}

void cloudrain::db::Management::createTable()
{
    using cloudrain::db::Schema;

    Schema schema("Management::createPrefix()");

   for(auto &i : schema.getSchema())
   {
        Management::query.prepare(i);
        Management::query.exec();
        if(true)
        {

        }
   }
}

QString cloudrain::db::Management::readPrefix()
{
    return "";
}

QString cloudrain::db::Management::createPrefix()
{
    return cloudrain::utility::sql::qGeneratePrefix(6);
}

void cloudrain::db::Management::deleteTable(QString name)
{
    Q_UNUSED(name)
}

void cloudrain::db::Management::insertIntoTable(QString name, QString values, QString table)
{
    Q_UNUSED(name)
    Q_UNUSED(values)
    Q_UNUSED(table)
}

void cloudrain::db::Management::SelectTable(QString name, QString table, QString where)
{
    Q_UNUSED(name)
    Q_UNUSED(table)
    Q_UNUSED(where)
}

void cloudrain::db::Management::updateTable(QString name, QString set, QString where)
{
    Q_UNUSED(name)
    Q_UNUSED(set)
    Q_UNUSED(where)
}
