#ifndef MENU_H
#define MENU_H
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>

#ifdef QT_DEBUG
#include <QDebug>
#endif

namespace cloudrain{
namespace gui {

class Menu : public QWidget
{
    private :
    public :
        explicit Menu(QWidget *parent = nullptr);
        virtual ~Menu();
};

}
}
#endif // MENU_H
