#ifndef GLOBAL_H
#define GLOBAL_H
#include <QString>

#ifdef QT_DEBUG
#endif

#ifdef QT_NO_DEBUG
#endif

namespace cloudraindaemon {
namespace global {

    namespace target {
        const QString ROOT_PATH = QStringLiteral("");
        namespace mysql {
            const QString MYSQL_LOG = QStringLiteral("");
            const QString MYSQL_VAR_ENV = QStringLiteral("");
            const QString MYSQL_PORT = QStringLiteral("");
        }
        namespace apache {
            const QString APACHE_DIR = QStringLiteral("");
            const QString APACHE_LOG = APACHE_DIR + QStringLiteral("");
            const QString APACHE_CONF = APACHE_DIR + QStringLiteral("");
            const QString APACHE_VIRTUAL_HOST = APACHE_DIR + QStringLiteral("");
        }
        namespace wamp {
            const QString WAMP_DIR = QStringLiteral("D:/wamp64/");
            const QString WAMP_MYSQL_LOG = WAMP_DIR + QStringLiteral("bin/mysql/mysql5.7.19/data/LAPTOP-C8DG8O99.log");
            const QString WAMP_MYSQL_ERR = WAMP_DIR + QStringLiteral("bin/mysql/mysql5.7.19/data/LAPTOP-C8DG8O99.err");
        }
    }
    namespace token {
        const QString uniqueToken = QStringLiteral("");
    }

}
}
#endif // GLOBAL_H
