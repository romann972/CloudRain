#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <chrono>
#include <random>
#include <sstream>

#include <QString>

/*
* utility function
*/

/*
* return sql prefix (std)
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
    }
}

// qGeneratePrefix
namespace cloudrain::utility {
    namespace sql{
        inline QString qGeneratePrefix(const int iteration)
        {
            return QString::fromStdString(generatePrefix(iteration));
        }
    }
}

// test timer (cout)
namespace cloudrain::utility {
    namespace {
        // static timer
    }
    namespace test {
        inline void timer()
        {

        }
    }
}

// test timer (qDebug)
namespace cloudrain::utility {
    namespace test {
        inline void qtimer()
        {

        }
    }
}

#endif // UTILITY_H
