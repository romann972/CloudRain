#ifndef SCHEMA_H
#define SCHEMA_H
#include <QStringList>
#include <QString>

namespace cloudrain {
namespace db {

    class Schema
    {
        private :
            QStringList allTables;

        public :
            Schema() = default;
            Schema(Schema &) = delete;
            Schema &operator=(Schema &) = delete;
            Schema(Schema &&) = delete;
            Schema &operator=(Schema &&) = delete;
            ~Schema() noexcept;
            QStringList getSchema() const;
    };

}
}

#endif // SCHEMA_H
