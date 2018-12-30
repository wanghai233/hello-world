#include "testpicture.h"
#include "ui_testpicture.h"

testPicture::testPicture(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::testPicture)
{
    ui->setupUi(this);
}

testPicture::~testPicture()
{
    delete ui;
}
