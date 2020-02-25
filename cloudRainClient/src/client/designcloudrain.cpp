#include <iostream>


/*
 * namespace  cloudrain normal
 * function/method camelCase
 * class/struct/union PascalCase
 * constant MAJUSCULE_STP
 * enum name normal
 * enum value _MAJUCULE_BONJOUR_
 * var camelCase
 *
 *
*/

/*
QLabel(const QString &text, QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags())
QPushButton(const QIcon &icon, const QString &text, QWidget *parent = nullptr)
QLineEdit(const QString &contents, QWidget *parent = nullptr)

 //ACCUEIL//
 QLabel = new QLabel("string");
 QButton = new QButton("string");
 QButton = new QButton("string");
 QButton = new QButton("string");
 QButton = new QButton("string");
 QButton = new QButton("string");

 //OPTIONS//
 QLabel optionsTitle = new QLabel();

 QComboBox selectLanguage = new QComboBox();

 QCheckBox serverLogs = new QCheckBox();
 QCheckBox websiteLogs = new QCheckBox();
 QCheckBox accessLogs = new QCheckBox();
 QCheckBox errorLogs = new QCheckBox();
 QCheckBox monitoringLogs = new QCheckBox();

 */

namespace  cloudrain::design {
    class DesignCloudRain {

    //CONNEXION//
    private:
        QMainWindow mainWindow = QMainWindow();
        QMainWindowTitle = new QMainWindowTitle("string");
       QLabel idLabel = new QLabel("ID : ", mainWindow );
       QLabel ipLabel = new QLabel("Adresse IP : ", mainWindow);
       QLabel usernameLabel = new QLabel("Username : ", mainWindow);
       QLabel connectionTitle = new QLabel("Connexion", mainWindow);
       QLineEdit idEdit = new QLineEdit();
        QLineEdit ipEdit = new QLineEdit();
        QLineEdit usernameEdit = new QLineEdit();
        QPushButton optionsButton = new QPushButton("Options");

    };
}

const int MA_CONSTANTE = 0;

int maVariable = 5;

void inline myFunction()
{
    std::cout << "myFunction \n";
}

class CloudRain
{

};

enum class bonjour {
    _MAJUCULE_BONJOUR_ = 0
};

/*
 * construction par defaut
 * mot clef explicit sur un constructeur différent
 * destructeur noexcept
*/


int main()
{
    return 0;
}
