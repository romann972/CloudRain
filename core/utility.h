#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <chrono>
#include <random>
#include <sstream>

#include <QString>
#include <QVector>
#include <QCryptographicHash>
#include <QRandomGenerator>

/*
* utility function
*/

// return std::string sql prefix (std)
namespace cloudrain::utility {

    namespace sql{

        // generatePrefix
        inline std::string generatePrefix(const int iteration)
        {
            std::string prefix;
            auto seed = std::chrono::system_clock::now().time_since_epoch().count();
            std::mt19937 mt(seed);

            auto MAJ = [&mt]()->int {
                std::uniform_int_distribution<int> dist(65, 90);
                return dist(mt);
            };

            auto NO_MAJ = [&mt]()->int {
                std::uniform_int_distribution<int> dist(97, 122);
                return dist(mt);
            };

            std::uniform_int_distribution<int> dist(1, 2);
            for(int i = 0; i < iteration; i++)
            {
                switch(dist(mt))
                {
                    case 1 : prefix += static_cast<char>(MAJ()); break;
                    case 2 : prefix += static_cast<char>(NO_MAJ()); break;
                    default : break;
                }
            }
            return prefix += "_";
        }

    } // END NAMESPACE sql

} // END NAMESPACE cloudrain::utility


// qGeneratePrefix
namespace cloudrain::utility {

    namespace sql{

        inline QString qGeneratePrefix(const int iteration)
        {
            return QString::fromStdString(generatePrefix(iteration));
        }

    } // END NAMESPACE sql

} // END NAMESPACE cloudrain::utility


// test timer (cout)
namespace cloudrain::utility {

    namespace timer {

        using clock = std::chrono::high_resolution_clock;
        static std::chrono::steady_clock::time_point beginTimer;

        void disableSyncStdio()
        {
            std::ios::sync_with_stdio(false);
            std::cin.tie (nullptr);
        }

        void startTimer()
        {
            beginTimer = std::chrono::steady_clock::now();
        }

        void endTimerUs()
        {
            std::chrono::steady_clock::time_point endTimer = std::chrono::steady_clock::now();
            std::cout << std::chrono::duration_cast<std::chrono::microseconds>(endTimer - beginTimer).count()
                      << " us \n";
        }

        void endTimerNs()
        {
            std::chrono::steady_clock::time_point endTimer = std::chrono::steady_clock::now();
            std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(endTimer - beginTimer).count()
                      << " ns \n";
        }

        void endTimerS()
        {
            std::chrono::steady_clock::time_point endTimer = std::chrono::steady_clock::now();
            std::cout << std::chrono::duration_cast<std::chrono::seconds>(endTimer - beginTimer).count()
                      << " s \n";
        }

    } // END NAMESPACE test

} // END NAMESPACE cloudrain::utility


// test timer (qDebug)
namespace cloudrain::utility {

    namespace test {

        inline void qtimer()
        {

        }

    } // END NAMESPACE test

} // END NAMESPACE cloudrain::utility


namespace cloudrain::utility {

    namespace crypto {

        enum hash {
            _MD4_ = 1,
            _MD5_ = 2,
            _SHA1_ = 3,
            _SHA2_224_ = 4,
            _SHA2_256_ = 5,
            _SHA2_384_ = 6,
            _SHA2_512_ = 7,
            _SHA3_224_ = 8,
            _SHA3_256_ = 9,
            _SHA3_384_ = 10,
            _SHA3_512_ = 11,
            _KECCAK_224_ = 12,
            _KECCAK_256_ = 13,
            _KECCAK_384_ = 14,
            _KECCAK_512_ = 15
        };

        QString hashGenerator(const QString method)
        {
            QVector<QString> hashMethod{
                                        "MD4","MD5","SHA1",
                                        "SHA2_224","SHA2_256","SHA2_384","SHA2_512",
                                        "SHA3_224","SHA3_256","SHA3_384","SHA3_512",
                                        "KECCAK_224","KECCAK_256","KECCAK_384","KECCAK_512"
                                        };
            int pos = 0;
            if(method != "random")
            {
                pos = [&hashMethod, &method]()->int {
                    for(int i = 0; i <  hashMethod.size();i++)
                    {
                        if(hashMethod[i] == method)
                        {
                            return i;
                        }
                    }
                    return 0;
                }();
            } else {
                pos = QRandomGenerator::global()->bounded(0,hashMethod.size());
            }
            QString resultHash;

            QString prefix = utility::sql::qGeneratePrefix(10);
            switch (pos)
            {
                case hash::_MD4_ :
                {
                    resultHash = QCryptographicHash::hash((prefix.toUtf8()),QCryptographicHash::Md4).toHex();
                } break;
                case hash::_MD5_ :
                {
                    resultHash = QCryptographicHash::hash((prefix.toUtf8()),QCryptographicHash::Md5).toHex();
                } break;
                case hash::_SHA1_ :
                {
                    resultHash = QCryptographicHash::hash((prefix.toUtf8()),QCryptographicHash::Sha1).toHex();
                } break;
                case hash::_SHA2_224_ :
                {
                    resultHash = QCryptographicHash::hash((prefix.toUtf8()),QCryptographicHash::Sha224).toHex();
                } break;
                case hash::_SHA2_256_ :
                {
                    resultHash = QCryptographicHash::hash((prefix.toUtf8()),QCryptographicHash::Sha256).toHex();
                } break;
                case hash::_SHA2_384_ :
                {
                    resultHash = QCryptographicHash::hash((prefix.toUtf8()),QCryptographicHash::Sha384).toHex();
                } break;
                case hash::_SHA2_512_ :
                {
                    resultHash = QCryptographicHash::hash((prefix.toUtf8()),QCryptographicHash::Sha512).toHex();
                } break;
                case hash::_SHA3_224_ :
                {
                    resultHash = QCryptographicHash::hash((prefix.toUtf8()),QCryptographicHash::Sha3_224).toHex();
                } break;
                case hash::_SHA3_256_ :
                {
                    resultHash = QCryptographicHash::hash((prefix.toUtf8()),QCryptographicHash::Sha3_256).toHex();
                } break;
                case hash::_SHA3_384_ :
                {
                    resultHash = QCryptographicHash::hash((prefix.toUtf8()),QCryptographicHash::Sha3_384).toHex();
                } break;
                case hash::_SHA3_512_ :
                {
                    resultHash = QCryptographicHash::hash((prefix.toUtf8()),QCryptographicHash::Sha3_512).toHex();
                } break;
                case hash::_KECCAK_224_ :
                {
                    resultHash = QCryptographicHash::hash((prefix.toUtf8()),QCryptographicHash::Keccak_224).toHex();
                } break;
                case hash::_KECCAK_256_ :
                {
                    resultHash = QCryptographicHash::hash((prefix.toUtf8()),QCryptographicHash::Keccak_256).toHex();
                } break;
                case hash::_KECCAK_384_ :
                {
                    resultHash = QCryptographicHash::hash((prefix.toUtf8()),QCryptographicHash::Keccak_384).toHex();
                } break;
                case hash::_KECCAK_512_ :
                {
                    resultHash = QCryptographicHash::hash((prefix.toUtf8()),QCryptographicHash::Keccak_512).toHex();
                } break;
                default :
                {
                    resultHash = QCryptographicHash::hash((prefix.toUtf8()),QCryptographicHash::Keccak_512).toHex();
                } break ;
            }
            return resultHash;
        }

    } // END NAMESPACE crypto

} // END NAMESPACE cloudrain::utility


// unique::token
namespace cloudrain::utility {

    namespace token {

        QString tokenGenerator(const QString method = "random")
        {
            return utility::crypto::hashGenerator(method);
        }

        // overload
        QString tokenGenerator(const int strLimit, const QString method = "random")
        {
            QString myHash = utility::crypto::hashGenerator(method);
            if(strLimit < myHash.size())
            {
                myHash = myHash.left(strLimit);
            }
            return myHash;
        }

    } // END NAMESPACE token

} // END NAMESPACE cloudrain::utility



#endif // UTILITY_H
