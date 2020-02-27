#include "Options.h"

cloudrain::gui::Options::Options(QWidget *parent)
    : QDialog(parent)
{
    this->setFixedSize(800,450);
    this->setWindowTitle(QObject::tr(""));
    this->setWindowIcon(QIcon("Icon en attente YaYa94"));

    QToolBar *toolBar = new QToolBar(this);
        QAction *openImage = new QAction("Open");
        QAction *editBar = new QAction("Edit");
        QAction *optionsBar = new QAction("Edit");
        QAction *langageBar = new QAction("Edit");
        QAction *helpBar = new QAction("Edit");

        //On doit faire un slot qui ouvre dans la fenêtre actuel l'image
        //connect(openImage, SIGNAL(triggered()), this, SLOT(affichageImage()));
        openImage->setShortcut(QKeySequence("Ctrl+O"));
        toolBar->addAction(openImage);

    QComboBox *languageComboBox = new QComboBox(this);
    QLabel *optionsTitleLabel = new QLabel("OPTIONS", this);
    QCheckBox *logsServerButton = new QCheckBox("Logs Server", this);
    QCheckBox *logsWebSiteButton = new QCheckBox("Logs WebSite", this);
    QCheckBox *logsAccessButton = new QCheckBox("Logs Access", this);
    QCheckBox *clearButton = new QCheckBox("Clear", this);

    languageComboBox->setGeometry(450, 250, 150 , 40);
    optionsTitleLabel->setGeometry(400, 50, 150 , 40);
    logsServerButton->setGeometry(50, 50, 150 , 40);
    logsWebSiteButton->setGeometry(50, 100, 150 , 40);
    logsAccessButton->setGeometry(50, 150, 150 , 40);
    clearButton->setGeometry(50, 250, 150 , 40);

    QObject::connect(logsServerButton, &QPushButton::clicked, []()->void {
        qDebug()<<"fff";
    });

    optionsTitleLabel->setAlignment(Qt::AlignRight);

    QObject::connect(logsServerButton, &QPushButton::clicked, []()->void {

    });
    this->cascadingStyleSheets();

}

void cloudrain::gui::Options::cascadingStyleSheets()
{
    this->setStyleSheet("QPushButton::hover {"
                            "background: transparent;"
                            "border-radius:20px;"
                            "border: 2px dotted;"
                        "}"
                        "QLabel::hover {"
                            "background-color: black;"
                        "}"
                        );
}

cloudrain::gui::Options::~Options() noexcept
{

}
