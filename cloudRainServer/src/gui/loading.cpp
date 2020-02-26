#include "loading.h"

cloudrain::gui::Loading::Loading(QWidget *parent)
    : QDialog(parent)
{
    this->setFixedSize(250, 250);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setAttribute(Qt::WA_PaintOnScreen);
}
void cloudrain::gui::Loading::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QColor color(0, 0, 0);
    color.setAlpha(0);
    painter.setBrush(QBrush(color));
    painter.setPen(Qt::NoPen);
    painter.drawRect(0, 0, this->width(), this->height());


}
cloudrain::gui::Loading::~Loading() noexcept
{

}
