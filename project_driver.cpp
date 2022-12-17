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
using namespace std;
project_driver::project_driver(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::project_driver)
{
    ui->setupUi(this);
}

project_driver::~project_driver()
{
    delete ui;
}

