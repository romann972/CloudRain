#include "management.h"

const QString Management::name = "QSQLITE";
QSqlDatabase Management::db = QSqlDatabase::addDatabase(name);
const QString Management::hostName="localhost";
const QString Management::path="path.db";
QSqlQuery Management::query = QSqlQuery(Management::db);


