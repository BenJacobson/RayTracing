#include <iostream>
#include "ppm.h"

PPM::PPM(int height, int width) {
    this->height = height;
    this->width = width;
    this->pixels = new int[height * width * 3];
}

void PPM::setPixel(int row, int col, int r, int g, int b) {
    int index = this->getIndex(row, col);
    this->pixels[index] = r;
    this->pixels[index+1] = g;
    this->pixels[index+2] = b;
}

void PPM::print() {
    std::cout << "P3\n";
    std::cout << this->width << ' ' << this->height << '\n';
    std::cout << "255\n";
    for (int i = 0, k = 0; i < this->height; ++i) {
        for (int j = 0; j < this->width; ++j, k += 3) {
            std::cout << this->pixels[k] << ' ' << this->pixels[k+1] << ' ' << this->pixels[k+2] << '\n';
        }
    }
}

int PPM::getIndex(int row, int col) {
    return (row * width + col) * 3;
}