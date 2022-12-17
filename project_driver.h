#ifndef PROJECT_DRIVER_H
#define PROJECT_DRIVER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class project_driver; }
QT_END_NAMESPACE

class project_driver : public QMainWindow
{
    Q_OBJECT

public:
    project_driver(QWidget *parent = nullptr);
    ~project_driver();

private:
    Ui::project_driver *ui;
};
#endif // PROJECT_DRIVER_H
