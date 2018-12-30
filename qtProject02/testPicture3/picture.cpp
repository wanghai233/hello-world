#include "picture.h"
#include "ui_picture.h"

picture::picture(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::picture)
{
    ui->setupUi(this);
}

picture::~picture()
{
    delete ui;
}

void picture::on_ButtonPic_clicked()
{
    QImage image;
    image.load("C:\Users\hai\Documents\QT_project\testPicture3.jpg");
    ui->labelPic->clear();
    ui->labelPic->setPixmap(QPixmap::fromImage(image));
}
