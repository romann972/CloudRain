#include "../core/utility.h"
#include "../core/jsonparser.h"
#include "../core/xmlparser.h"

#include <QDebug>

int main()
{
    //test timer
    cloudrain::utility::timer::startTimer();

    // std prefix
    std::cout <<  "prefixGenerator with 5 character -> " << cloudrain::utility::sql::generatePrefix(5) << std::endl;

    // Qt prefix
    qDebug() << "qprefixGenerator with 5 character -> " << cloudrain::utility::sql::qGeneratePrefix(5);

    // QT token
    qDebug() << "tokenGenerator basic -> " << cloudrain::utility::token::tokenGenerator();
    qDebug() << "tokenGenerator with a MD5 method -> " << cloudrain::utility::token::tokenGenerator("MD5");

    // QT token overload
    qDebug() << "tokenGenerator with a limit of 10 -> " << cloudrain::utility::token::tokenGenerator(10, "MD5");

    // cout end - start Seconds
    cloudrain::utility::timer::endTimerS();

    // cout end - start micro seconds
    cloudrain::utility::timer::endTimerUs();

    // cout end - start Nano seconds
    cloudrain::utility::timer::endTimerNs();

    cloudrain::utility::parser::JsonParser jsonParser;
    return 0;
}
