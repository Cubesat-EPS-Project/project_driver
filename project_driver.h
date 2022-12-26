#ifndef PROJECT_DRIVER_H
#define PROJECT_DRIVER_H

#include <QMainWindow>
#include <QClipboard>
QT_BEGIN_NAMESPACE
namespace Ui { class project_driver; }
QT_END_NAMESPACE

class project_driver : public QMainWindow
{
    Q_OBJECT

public:
    project_driver(QWidget *parent = nullptr);
    ~project_driver();

private slots:
    void on_pushButton_clicked();

    void on_swfm_currentIndexChanged(int index);

    void on_irpsugg_clicked();

    void on_ilrippslider_sliderMoved(int position);

    void on_swf_valueChanged(double arg1);

    void on_horizontalSlider_sliderMoved(int position);

    void on_designbtn_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_boostfreqmul_currentIndexChanged(int index);

    void on_boostfreq_valueChanged(double arg1);

    void on_boosteff_sliderMoved(int position);

    void on_pushButton_7_clicked();

private:
    Ui::project_driver *ui;
};
#endif // PROJECT_DRIVER_H
