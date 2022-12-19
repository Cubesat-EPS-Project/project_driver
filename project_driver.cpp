#include "project_driver.h"
#include "./ui_project_driver.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <QString>
//#include <QQmlContext>
#include <unistd.h>
#include <ios>
#include <fstream>
#include <string>
#include <QFileDialog>
#include <QProcess>
#include <QFile>
#include <QTextStream>
#include <QTextCursor>
#include <QClipboard>
#include <QMessageBox>
using namespace std;
double vin1=0;
double vout1=0;
double duty=0;
double iomax1=-1;
double hiomax=77.0;
double liomax=0;
double iripple=1.0;
double swf=0;
double capripp=1.0;
int swmul=1000;
int mul=1000;
double indexsw=-1;
double eff=100.0;
double buckindc=-1.0;
double buckcap=-1.0;
project_driver::project_driver(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::project_driver)
{
    ui->setupUi(this);
}
QClipboard *clipboard = QApplication::clipboard();

project_driver::~project_driver()
{
    delete ui;
}


void project_driver::on_pushButton_clicked()
{
    vin1=ui->vin->text().toDouble();
    vout1=ui->vout->text().toDouble();
    duty=vout1/(vin1*(eff/100));
    //QString dutyst = QString::number(duty);
    ui->lcdNumber->display(duty);
    //ui->duty->setText(dutyst);
}


void project_driver::on_swfm_currentIndexChanged(int index)
{   indexsw=index;
    swf=ui->swf->text().toDouble();
    if(index==0)
    {
        swmul=1000*swf;
        mul=1000;
        ui->swf_2->setText(QString::number(swmul));
    }
    if(index==1)
    {
        swmul=1000000*swf;
        mul=1000000;
        ui->swf_2->setText(QString::number(swmul));
    }
    if(index==-1)
    {
        swmul=1000*swf;
        ui->swf_2->setText(QString::number(swmul));
    }
}


void project_driver::on_irpsugg_clicked()
{
    iomax1=ui->iomax->text().toDouble();

    liomax=0.2*iomax1*1000000;
    hiomax=0.4*iomax1*1000000;
    ui->ilrippslider->setSingleStep(10000);
    ui->ilrippslider->setMinimum((int)liomax);
    ui->ilrippslider->setMaximum((int)hiomax);


}


void project_driver::on_ilrippslider_sliderMoved(int position)
{
    iripple=(double)position/1000000.0;
    ui->iripp->setText(QString::number(iripple));
}


void project_driver::on_swf_valueChanged(double arg1)
{

    ui->swf_2->setText(QString::number(mul*arg1));

}


void project_driver::on_horizontalSlider_sliderMoved(int position)
{
    eff=(double)position/10;
    ui->lcdNumber_2->display(eff);
}


void project_driver::on_designbtn_clicked()
{
    vin1=ui->vin->text().toDouble();
    vout1=ui->vout->text().toDouble();
    capripp=ui->vripp->text().toDouble();
    swf=ui->swf->text().toDouble();
    if(indexsw==0)
    {
        swmul=1000*swf;
        mul=1000;
        ui->swf_2->setText(QString::number(swmul));
    }
    if(indexsw==1)
    {
        swmul=1000000*swf;
        mul=1000000;
        ui->swf_2->setText(QString::number(swmul));
    }
    if(indexsw==-1)
    {
        swmul=1000*swf;
        ui->swf_2->setText(QString::number(swmul));
    }
    duty=vout1/(vin1*(eff/100));
    on_pushButton_clicked();
    buckindc=(vin1*duty*(1-duty))/(swmul*iripple);
    ui->indcbk->setText(QString::number(buckindc));

    buckcap=(vout1*(1-duty))/(8*buckindc*capripp*swmul*swmul);
    ui->capval->setText(QString::number(buckcap));
}


void project_driver::on_pushButton_2_clicked()
{
    QString indc1buk=QString::number(buckindc);
    clipboard->setText(indc1buk);
    //ui->indcbk->copy();
}


void project_driver::on_pushButton_3_clicked()
{
    QString capvalbuck=QString::number(buckcap);
    clipboard->setText(capvalbuck);
    //ui->capval->copy();
}

