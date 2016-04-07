#include "opencv_drawer.h"

Opencv_Drawer::Opencv_Drawer(int width, int height, int ap)
{
    img = Mat::zeros(width, height, CV_8UC3);
    anti_para = ap;
    weight_table = new int[anti_para * anti_para];
    // Default setting of weight
    weight_sum = 16;
    weight_table[0] = weight_table[2] = weight_table[6] = weight_table[8] = 1;
    weight_table[1] = weight_table[3] = weight_table[5] = weight_table[7] = 2;
    weight_table[4] = 4;
}

void Opencv_Drawer::Bresenhamline(int x0, int y0, int x1, int y1, Vec3b& bgr, bool enable_antialias)
{
    if (iflegal(x0, y0) && iflegal(x1, y1))
    {
        if (x0 == x1)
        {
            if (y0 > y1)
                swap(y0, y1);
            for (int i = y0; i < y1; ++i)
                draw_pixel(x0, i, bgr);
            return;
        }
        else
        {
            if (enable_antialias) { // Transfer to a densed area
                x0 = x0 * anti_para;
                y0 = y0 * anti_para;
                x1 = x1 * anti_para;
                y1 = y1 * anti_para;
            }
            if (abs(x1 - x0) >= abs(y1 - y0))
            {
                if (x0 > x1)
                {
                    swap(x0, x1);
                    swap(y0, y1);
                }
                int dx = x1 - x0, dy = y1 - y0;
                int x = x0, y = y0, e = -dx;
                int absdy = abs(dy), inc = (dy >= 0) ? 1 : -1;
                if (enable_antialias) {
                    Mat buffer = Mat::zeros(anti_para, anti_para * 3, CV_8UC3); // 3 means upper, middle and bottom
                    int act_x = 0, act_y = 0;
                    for (int i = 0; i <= dx; ++i)
                    {
                        for (int w = 0; w < anti_para; ++w) {
                            buffer.at<Vec3b>(x % anti_para, y % anti_para + w) = bgr;
                        }
                        if (x % anti_para == 0) {
                            act_x = x / anti_para;
                            act_y = y / anti_para;
                        }
                        if (x % anti_para == anti_para - 1) {
                            for (int k = 0; k < 2; ++k) {
                                int startx = 0;
                                int starty = k * anti_para;
                                if (iflegal(act_x, act_y + k)) {
                                    int bsum = 0, gsum = 0, rsum = 0;
                                    for (int pick_x = 0; pick_x < anti_para; ++pick_x) {
                                        for (int pick_y = 0; pick_y < anti_para; ++pick_y) {
                                            bsum += (weight_table[pick_x * anti_para + pick_y] * buffer.at<Vec3b>(pick_x, pick_y + starty)[0]);
                                            gsum += (weight_table[pick_x * anti_para + pick_y] * buffer.at<Vec3b>(pick_x, pick_y + starty)[1]);
                                            rsum += (weight_table[pick_x * anti_para + pick_y] * buffer.at<Vec3b>(pick_x, pick_y + starty)[2]);
                                        }
                                    }
                                    img.at<Vec3b>(act_x, act_y + k)[0] = (int)((double)bsum / weight_sum);
                                    img.at<Vec3b>(act_x, act_y + k)[1] = (int)((double)gsum / weight_sum);
                                    img.at<Vec3b>(act_x, act_y + k)[2] = (int)((double)rsum / weight_sum);
                                }
                            }
                            buffer = Mat::zeros(anti_para, anti_para * 3, CV_8UC3);
                        }
                        ++x;
                        e += 2 * absdy;
                        if (e >= 0)
                        {
                            y += inc;
                            e -= (2 * dx);
                        }
                    }
                }
                else {
                    for (int i = 0; i <= dx; ++i)
                    {
                        draw_pixel(x++, y, bgr);
                        e += 2 * absdy;
                        if (e >= 0)
                        {
                            y += inc;
                            e -= (2 * dx);
                        }
                    }
                }
            }
            else
            {
                if (y0 > y1)
                {
                    swap(x0, x1);
                    swap(y0, y1);
                }
                int dx = x1 - x0, dy = y1 - y0;
                int x = x0, y = y0, e = -dy;
                int absdx = abs(dx), inc = (dx >= 0) ? 1 : -1;
                if (enable_antialias) {
                    Mat buffer = Mat::zeros(anti_para * 3, anti_para, CV_8UC3); // 3 means upper, middle and bottom
                    int act_y = 0, act_x = 0;
                    for (int i = 0; i <= dy; ++i)
                    {
                        for (int w = 0; w < anti_para; ++w) {
                            buffer.at<Vec3b>(x % anti_para + w, y % anti_para) = bgr;
                        }
                        if (y % anti_para == 0) {
                            act_x = x / anti_para;
                            act_y = y / anti_para;
                        }
                        if (y % anti_para == anti_para - 1) {
                            for (int k = 0; k < 2; ++k) {
                                int starty = 0;
                                int startx = k * anti_para;
                                if (iflegal(act_x + k, act_y)) {
                                    int bsum = 0, gsum = 0, rsum = 0;
                                    for (int pick_x = 0; pick_x < anti_para; ++pick_x) {
                                        for (int pick_y = 0; pick_y < anti_para; ++pick_y) {
                                            bsum += (weight_table[pick_x * anti_para + pick_y] * buffer.at<Vec3b>(pick_x + startx, pick_y)[0]);
                                            gsum += (weight_table[pick_x * anti_para + pick_y] * buffer.at<Vec3b>(pick_x + startx, pick_y)[1]);
                                            rsum += (weight_table[pick_x * anti_para + pick_y] * buffer.at<Vec3b>(pick_x + startx, pick_y)[2]);
                                        }
                                    }
                                    img.at<Vec3b>(act_x + k, act_y)[0] = (int)((double)bsum / weight_sum);
                                    img.at<Vec3b>(act_x + k, act_y)[1] = (int)((double)gsum / weight_sum);
                                    img.at<Vec3b>(act_x + k, act_y)[2] = (int)((double)rsum / weight_sum);
                                }
                            }
                            buffer = Mat::zeros(anti_para * 3, anti_para, CV_8UC3);
                        }
                        ++y;
                        e += 2 * absdx;
                        if (e >= 0)
                        {
                            x += inc;
                            e -= (2 * dy);
                        }
                    }
                }
                else {
                    for (int i = 0; i <= dy; ++i)
                    {
                        draw_pixel(x, y++, bgr);
                        e += 2 * absdx;
                        if (e >= 0)
                        {
                            x += inc;
                            e -= (2 * dy);
                        }
                    }
                }
            }
        }

    }
    else
    {
        // cerr << "Illegal points!" << x0 << ' ' << y0 << ' ' << x1 << ' ' << y1 << endl;
        return;
    }
}

bool Opencv_Drawer::iflegal(int x0, int y0)
{
    return (0 <= x0 && x0 < img.rows && 0 <= y0 && y0 < img.cols);
}

void Opencv_Drawer::draw_pixel(int x0, int y0, Vec3b &bgr)
{
    assert (iflegal(x0, y0));
    Vec3b &imgbgr = img.at<Vec3b>(x0, y0);
    imgbgr = bgr;
}

QImage Opencv_Drawer::cvmat2qtimage()
{
    QImage qtimage(img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);
    return qtimage.rgbSwapped();
}
