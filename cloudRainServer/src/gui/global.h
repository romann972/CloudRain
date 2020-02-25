#ifndef GLOBAL_H
#define GLOBAL_H
#include <QString>

#ifdef QT_DEBUG
#endif

#ifdef QT_NO_DEBUG
#endif

namespace cloudrain::gui::global {
#ifdef QT_DEBUG
    const QString PATH = ""; // your path
#endif

#ifdef QT_NO_DEBUG
    const QString PATH = ""; // real path
#endif

    namespace img {
        // example
        const QString BACKGROUND = PATH + "/rcs/background.png";

        // use cloudrain::gui::global::img::BACKGROUND
        // or
        // destroy namespace
        // using namespace cloudrain::gui::global::img
        // use BACKGROUND
    }
    namespace icon {

    }
    namespace target {
        namespace  {

        }
    }
}
#endif // GLOBAL_H
