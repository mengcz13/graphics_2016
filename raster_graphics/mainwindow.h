#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QList>
#include "opencv_drawer.h"

struct MyLine {
    QPoint start;
    QPoint end;
    Vec3b bgr;
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void draw_qpix();
    QPoint get_rela_pos(QPoint);
    void draw_all_lines();
    ~MainWindow();

private slots:
    void on_DrawLinepushButton_clicked();

    void on_clearButton_clicked();

    void mousePressEvent(QMouseEvent* m);

    void mouseMoveEvent(QMouseEvent* m);

    void mouseReleaseEvent(QMouseEvent* m);

private:
    Ui::MainWindow *ui;
    Opencv_Drawer opencvdrawer;
    QList<MyLine> linelist;
};

#endif // MAINWINDOW_H
