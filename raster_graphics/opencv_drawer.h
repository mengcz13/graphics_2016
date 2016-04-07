#ifndef OPENCV_DRAWER_H
#define OPENCV_DRAWER_H

#include <iostream>
#include <cassert>
#include <algorithm>
#include <opencv2/opencv.hpp>
#include <QImage>

using namespace std;
using namespace cv;

const int DEFAULT_SIZE = 400;
const int DEFAULT_ANTI_PARA = 3;

class Opencv_Drawer
{
public:
    Opencv_Drawer(int width = DEFAULT_SIZE, int height = DEFAULT_SIZE, int ap = DEFAULT_ANTI_PARA);
    ~Opencv_Drawer() { delete []weight_table; }
    void Bresenhamline(int x0, int y0, int x1, int y1, Vec3b& bgr, bool enable_antialias = true); // Draw a line (x0, y0) -> (x1, y1) using Bresenham algorithm
    // void Bresen_antialias_line(int x0, int y0, int x1, int y1, Vec3b& bgr);
    bool iflegal(int x0, int y0); // Judge if (x0, y0) is in the img.
    void draw_pixel(int x0, int y0, Vec3b& bgr); //Draw a pixel at (x0, y0) with color bgr. X axis is vertical and Y axis is horizonal. (0, 0) is the left-up-most point.
    QImage cvmat2qtimage();
    int width() { return img.cols; }
    int height() { return img.rows; }
    void clear() { img = Mat::zeros(img.rows, img.cols, CV_8UC3); }
private:
    Mat img;
    int anti_para;
    int* weight_table;
    int weight_sum;
};

#endif // OPENCV_DRAWER_H
