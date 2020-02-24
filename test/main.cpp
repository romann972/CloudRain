#include "../core/utility.h"
#include <QDebug>

int main()
{
    //std prefix
    std::cout << cloudrain::utility::sql::generatePrefix(5) << std::endl;

    //Qt prefix
    qDebug()<<cloudrain::utility::sql::qGeneratePrefix(5);
    return 0;
}
