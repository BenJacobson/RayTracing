#include <iostream>
#include "ppm.h"

PPM::PPM(int height, int width, unsigned int color_bits) {
    this->max_color_ = (1u << color_bits) - 1;
    this->height_ = height;
    this->width_ = width;
    this->pixels_ = new int[height * width * 3];
}

void PPM::setPixel(int row, int col, const Vec3& color) {
    int index = this->getIndex(row, col);
    this->pixels_[index] = int(color.r() * (max_color_ + .99));
    this->pixels_[index+1] = int(color.g() * (max_color_ + .99));
    this->pixels_[index+2] = int(color.b() * (max_color_ + .99));
}

void PPM::print() {
    std::cout << "P3\n";
    std::cout << this->width_ << ' ' << this->height_ << '\n';
    std::cout << max_color_ << '\n';
    for (int i = 0, k = 0; i < this->height_; ++i) {
        for (int j = 0; j < this->width_; ++j, k += 3) {
            std::cout << this->pixels_[k] << ' ' << this->pixels_[k+1] << ' ' << this->pixels_[k+2] << '\n';
        }
    }
}

int PPM::getIndex(int row, int col) {
    return (row * width_ + col) * 3;
}
