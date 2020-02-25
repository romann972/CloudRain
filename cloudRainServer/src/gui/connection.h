#ifndef CONNECTION_H
#define CONNECTION_H
#include <QWidget>


namespace cloudrain{
namespace gui {

    class Connection : public QWidget
    {
        Q_OBJECT

        private :
        protected:
        public :
            explicit Connection(QWidget *parent = nullptr);
            virtual ~Connection() noexcept;
    };

}
}

#endif // CONNECTION_H
