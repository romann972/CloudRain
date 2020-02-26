#include "mainwindow.h"

cloudrain::gui::MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //Affichage de l'image dans le fond
    QLabel *label = new QLabel(this);
    QPixmap pixmap("C:/cloudrain.jpg");
    label->setPixmap(pixmap);
    label->resize(pixmap.size());

    // UI WINDOWS //
    setFixedSize(800,450);
    setWindowIcon(QIcon("path"));

    this->widgetStack = new QStackedWidget(this);
    this->menu = new Menu(this);
    this->options = new Options(this);
    this->connection = new Connection(this);

    this->widgetStack->addWidget(menu);
    this->widgetStack->addWidget(options);
    this->widgetStack->addWidget(connection);
    this->widgetStack->setCurrentIndex(0);

    this->setCentralWidget(this->widgetStack);

    QToolBar *toolBar = new QToolBar(this);
        QAction *openImage = new QAction("Open");
        connect(openImage, SIGNAL(triggered()), this, SLOT(openImage()));
        openImage->setShortcut(QKeySequence("Ctrl+O"));
        toolBar->addAction(openImage);


        QAction *editBar = new QAction("Edit");

        QAction *settingsAction = new QAction("Settings");
        connect(settingsAction, SIGNAL(triggered()), this, SLOT(options()));
        toolBar->addAction(settingsAction);

        QAction *languageBar = new QAction("Language");

        QAction *helpAction = new QAction("Help");
        connect(helpAction, SIGNAL(triggered()), this, SLOT(docDisplay()));
        helpAction->setShortcut(QKeySequence("Ctrl+H"));
        toolBar->addAction(helpAction);

        QAction *leaveAction = new QAction("Help");
        connect(leaveAction, SIGNAL(triggered()), qApp, SLOT(quit()));
        leaveAction->setShortcut(QKeySequence("Ctrl+Q"));
        toolBar->addAction(leaveAction);

        toolBar->addAction(editBar);
        toolBar->addAction(languageBar);
}

cloudrain::gui::MainWindow::~MainWindow() noexcept
{

}

void MainWindow::openImage() {
    QString file = QFileDialog::getOpenFileName(this, "Open an image", QString(), "Images (*.png *.gif *.jpg *.jpeg)");
    setCheminImage(file);

    QString image = getCheminImage();
    int x = this->ui->lImage->width();
    int y = this->ui->lImage->height();
    QPixmap *pixmap_img = new QPixmap(image);
    this->ui->lImage->setPixmap(pixmap_img->scaled(x,y));
}

void MainWindow::docDisplay() {
    QDesktopServices::openUrl(QUrl("C:/GitHub/Cloudrain/Mode_d'emploi.pdf",QUrl::TolerantMode));
}
