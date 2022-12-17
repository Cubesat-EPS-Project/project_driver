#include "project_driver.h"
#include "./ui_project_driver.h"

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

