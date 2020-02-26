#ifndef SCHEMA_H
#define SCHEMA_H
#include <QStringList>
#include <QString>

namespace cloudrain {
namespace db {

    class Schema
    {
        private :
            QStringList tables;
            const QString prefix;

        public :
            Schema(const QString prefix);
            Schema(Schema &) = delete;
            Schema &operator=(Schema &) = delete;
            Schema(Schema &&) = delete;
            Schema &operator=(Schema &&) = delete;
            ~Schema() noexcept;

            // schema
            QStringList getSchema();

            // table
            QString getServer();
            QString getTime();
            QString getSrvInfo();

            QString getClient();

            QString getMysql();
            QString getMysqlMeta();
            QString getAnalyseMysql() ;

            QString getApache();
            QString getApacheMeta();
            QString getAnalyseApache();
    };

}
}

#endif // SCHEMA_H
