#ifndef PPM_H_
#define PPM_H_

class PPM {
public:
    PPM(int height, int width);
    void setPixel(int row, int col, int r, int g, int b);
    void print();

private:
    int getIndex(int row, int col);

    int height;
    int width;
    int *pixels;
};

#endif
