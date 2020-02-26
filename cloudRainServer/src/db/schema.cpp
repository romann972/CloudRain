#include "schema.h"

cloudrain::db::Schema::Schema(const QString prefix) : prefix(prefix)
{
    tables << getServer()
           << getTime()
           << getSrvInfo()
           << getClient()
           << getMysql()
           << getMysqlMeta()
           << getAnalyseMysql()
           << getApache()
           << getApacheMeta()
           << getAnalyseApache();
}

QStringList cloudrain::db::Schema::getSchema()
{
    return this->tables;
}

QString cloudrain::db::Schema::getServer()
{
    return "";
}
QString cloudrain::db::Schema::getTime()
{
    return "";
}
QString cloudrain::db::Schema::getSrvInfo()
{
   return "";
}

QString cloudrain::db::Schema::getClient()
{
    QString client = "CREATE TABLE IF NOT EXISTS "+ this->prefix +"client "
                     "("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "name VARCHAR(100) NOT NULL,"
                        "ip VARCHAR(32) NOT NULL,"
                        "date_GMT DATE NOT NULL,"
                        "date_UTC DATE NOT NULL,"
                        "status VARCHAR(100) NOT NULL"
                      ");";
    return client;
}

QString cloudrain::db::Schema::getMysql()
{
    QString mysql = "CREATE TABLE IF NOT EXISTS "+ this->prefix +"mysql"
                    "("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "id_client INTEGER,"
                        "date_GMT DATE NOT NULL,"
                        "date_UTC DATE NOT NULL,"
                        "FOREIGN KEY(id_client) REFERENCES user(id)"
                    ");";
    return mysql;
}
QString cloudrain::db::Schema::getMysqlMeta()
{
    QString mysqlMeta = "CREATE TABLE IF NOT EXISTS"+ this->prefix +"mysql_meta"
                        "("
                            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                            "meta_key VARCHAR(100) NOT NULL,"
                            "meta_value TEXT,"
                            "id_mysql INTEGER,"
                            "FOREIGN KEY(id_mysql) REFERENCES mysql(id)"
                          ");";
    return mysqlMeta;
}
QString cloudrain::db::Schema::getAnalyseMysql()
{
    QString analyseMysql = "CREATE TABLE IF NOT EXISTS"+ this->prefix +" analyse_mysql"
                           "("
                           ");";
    return analyseMysql;
}

QString cloudrain::db::Schema::getApache()
{
    QString apache = "CREATE TABLE IF NOT EXISTS "+ this->prefix +"apache"
                     "("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "id_client INTEGER,"
                        "date_GMT DATE NOT NULL,"
                        "date_UTC DATE NOT NULL,"
                        "FOREIGN KEY(id_client) REFERENCES user(id)"
                    ");";
    return apache;
}
QString cloudrain::db::Schema::getApacheMeta()
{
    QString apacheMeta = "CREATE TABLE IF NOT EXISTS" "apache_meta"
                         "("
                            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                            "meta_key VARCHAR(100) NOT NULL,"
                            "meta_value TEXT,"
                            "id_apache INTEGER,"
                            "FOREIGN KEY(id_apache) REFERENCES apache(id)"
                          ");";
    return apacheMeta;
}
QString cloudrain::db::Schema::getAnalyseApache()
{
    QString analyseMysql = "CREATE TABLE IF NOT EXISTS"+ this->prefix +" analyse_apache"
                           "("
                                "id INTEGER PRIMARY KEY AUTOINCREMENT"
                           ");";
    return analyseMysql;
}

cloudrain::db::Schema::~Schema() noexcept
{

}


