#include "ppmlib/ppm.h"

#include <fstream>
#include <iostream>
#include <cstddef>
#include <cstdint>
#include <cstdlib>

using namespace ppmlib;

PPM::PPM(size_t width, size_t height) : mWidth(width), mHeight(height) {
    mData = (uint8_t*) calloc(sizeof(uint8_t), width * height * 3);
}

PPM::~PPM() {
    free(mData);
}

size_t PPM::getWidth() {
    return mWidth;
}

size_t PPM::getHeight() {
    return mHeight;
}

void PPM::setPixel(size_t x, size_t y, uint8_t r, uint8_t g, uint8_t b) {
    mData[y * (mWidth * 3) + x * 3 + 0] = r;
    mData[y * (mWidth * 3) + x * 3 + 1] = g;
    mData[y * (mWidth * 3) + x * 3 + 2] = b;
}

void PPM::getPixel(size_t x, size_t y, uint8_t* out) {
    for (size_t i = 0; i < 3; i++) {
        out[i] = mData[y * (mWidth * 3) + x * 3 + i];
    }
}

void PPM::writeToFile(const char* fileName) {
    std::ofstream out(fileName, std::ios::binary);
    out << "P6\n";
    out << mWidth << " " << mHeight << "\n";
    out << "255\n";
    out.write(reinterpret_cast<char*>(mData), sizeof(uint8_t) * mHeight * mWidth * 3);
}

PPM PPM::loadFromFile(const char* fileName) {
    return PPM(640, 480);
}

