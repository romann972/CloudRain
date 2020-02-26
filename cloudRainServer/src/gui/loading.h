#ifndef LOADING_H
#define LOADING_H
#include <QDialog>
#include <QKeyEvent>
#include <QPainter>

#ifdef QT_DEBUG
#include <QDebug>
#endif

namespace cloudrain {
namespace gui {

    class Loading : public QDialog
    {
        private :
        public :
        explicit Loading(QWidget *parent = nullptr);
        virtual void paintEvent(QPaintEvent *) override;
        virtual ~Loading() noexcept override;
    };

}
}
#endif // LOADING_H
