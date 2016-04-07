#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    draw_qpix();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::draw_qpix()
{
    QImage img = opencvdrawer.cvmat2qtimage();
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->resize(img.width(), img.height());
}

QPoint MainWindow::get_rela_pos(QPoint m)
{
    QPoint rela_pos = m - ui->label->pos();
    int t = rela_pos.x();
    rela_pos.setX(rela_pos.y());
    rela_pos.setY(t);
    return rela_pos;
}

void MainWindow::draw_all_lines()
{
    MyLine l;
    opencvdrawer.clear();
    foreach (l, linelist) {
        opencvdrawer.Bresenhamline(l.start.x(), l.start.y(), l.end.x(), l.end.y(), l.bgr);
    }
    draw_qpix();
}

void MainWindow::on_DrawLinepushButton_clicked()
{
    MyLine line;
    line.bgr[0] = ui->BspinBox_7->value();
    line.bgr[1] = ui->GspinBox_6->value();
    line.bgr[2] = ui->RspinBox_5->value();
    line.start = QPoint(ui->X0spinBox->value(), ui->Y0spinBox_2->value());
    line.end = QPoint(ui->X1spinBox_3->value(), ui->Y1spinBox_4->value());
    linelist.append(line);
    draw_all_lines();
}

void MainWindow::on_clearButton_clicked()
{
    opencvdrawer.clear();
    linelist.clear();
    draw_qpix();
}

void MainWindow::mousePressEvent(QMouseEvent *m)
{
    QPoint rela_pos = get_rela_pos(m->pos());
    MyLine line;
    line.bgr[0] = ui->BspinBox_7->value();
    line.bgr[1] = ui->GspinBox_6->value();
    line.bgr[2] = ui->RspinBox_5->value();
    line.start = rela_pos;
    line.end = QPoint(0, 0);
    linelist.append(line);
}

void MainWindow::mouseMoveEvent(QMouseEvent *m)
{
    linelist.back().end = get_rela_pos(m->pos());
    draw_all_lines();
}


void MainWindow::mouseReleaseEvent(QMouseEvent *m)
{

}
