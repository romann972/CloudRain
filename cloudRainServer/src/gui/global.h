#ifndef GLOBAL_H
#define GLOBAL_H
#include <QString>

#ifdef QT_DEBUG
#endif

#ifdef QT_NO_DEBUG
#endif

namespace cloudrain {
namespace gui {
namespace global {

#ifdef QT_DEBUG
    const QString PATH = QStringLiteral("D:/Qt programmation/cloudrain/CloudRain/cloudRainServer/build/windows/rcs");
#endif

#ifdef QT_NO_DEBUG
    const QString PATH = "/rcs"; // real path
#endif

    namespace img {
        // example


        // use cloudrain::gui::global::img::BACKGROUND
        // or
        // destroy namespace
        // using namespace cloudrain::gui::global::img
        // use BACKGROUND
    }
    namespace icon {
        const QString FLAG_FR = PATH + QStringLiteral("/icon/france.png");
        const QString FLAG_AR = PATH + QStringLiteral("/icon/algeria.png");
        const QString FLAG_US = PATH + QStringLiteral("/icon/united_states_of_america.png");
        const QString FLAG_PL = PATH + QStringLiteral("/icon/portugal.png");

        const QString HELP_512 = PATH + QStringLiteral("/icon/help_512.png");
        const QString INFO_512 = PATH + QStringLiteral("/icon/information_512.png");
        const QString SETTINGS_512 = PATH + QStringLiteral("/icon/settings_512.png");
        const QString CANCEL_512 = PATH + QStringLiteral("/icon/cancel_512.png");
        const QString TICK_512 = PATH + QStringLiteral("/icon/tick_512.png");
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
}
}
#endif // GLOBAL_H
