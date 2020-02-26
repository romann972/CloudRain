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
            QStringList getSchema() const;

            // table
            QString getServer() const;
            QString getTime() const;
            QString getSrvInfo() const;

            QString getClient() const;

            QString getMysql() const;
            QString getMysqlMeta() const;
            QString getAnalyseMysql() const;

            QString getApache() const;
            QString getApacheMeta() const;
            QString getAnalyseApache() const;
    };

}
}

#endif // SCHEMA_H
