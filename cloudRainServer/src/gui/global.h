#ifndef GLOBAL_H
#define GLOBAL_H
#include <QString>

#ifdef QT_DEBUG
#endif

#ifdef QT_NO_DEBUG
#endif

namespace cloudrain::gui::global {
#ifdef QT_DEBUG
    const QString PATH = QStringLiteral(""); // your path
#endif

#ifdef QT_NO_DEBUG
    const QString PATH = ""; // real path
#endif

    namespace img {
        // example
        const QString BACKGROUND = PATH + QStringLiteral("/rcs/background.png");

        // use cloudrain::gui::global::img::BACKGROUND
        // or
        // destroy namespace
        // using namespace cloudrain::gui::global::img
        // use BACKGROUND
    }
    namespace icon {

    }
    namespace target {
        const QString ROOT_PATH = QStringLiteral("");
        namespace mysql {
            const QString MYSQL_LOG = PATH + QStringLiteral("");
            const QString MYSQL_VAR_ENV = QStringLiteral("");
            const QString MYSQL_PORT = QStringLiteral("");
        }
        namespace apache {
            const QString APACHE_DIR = QStringLiteral("");
            const QString APACHE_LOG = APACHE_DIR + QStringLiteral("");
            const QString APACHE_CONF = APACHE_DIR + QStringLiteral("");
            const QString APACHE_VIRTUAL_HOST = APACHE_DIR + QStringLiteral("");
        }
    }
}
#endif // GLOBAL_H
