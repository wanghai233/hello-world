#include "ppms.h"
#include "ui_ppms.h"

ppms::ppms(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ppms)
{
    ui->setupUi(this);
    QRegExp regx("[0-9]+$");
    QValidator *validator= new QRegExpValidator(regx,this);
    ui->lineEdit->setValidator(validator);

}

ppms::~ppms()
{
    delete ui;
}

void ppms::on_pushButton_3_clicked()
{
    this->close();
}
