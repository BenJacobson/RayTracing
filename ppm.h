#ifndef PPM_H_
#define PPM_H_

#include "vec3.h"

class PPM {
public:
    PPM(int height, int width, unsigned int color_bits);
    void setPixel(int row, int col, const Vec3& color);
    void print();

private:
    int getIndex(int row, int col);

    int max_color_;
    int height_;
    int width_;
    int *pixels_;
};

#endif
