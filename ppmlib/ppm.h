#ifndef _PPMLIB_PPM_H
#define _PPMLIB_PPM_H

#include <cstddef>
#include <cstdint>

namespace ppmlib {

class PPM {
public:
    PPM(size_t width, size_t height);
    ~PPM();

    size_t getWidth();
    size_t getHeight();
    size_t getDepth();
    void setPixel(size_t x, size_t y, uint8_t r, uint8_t g, uint8_t b);
    void getPixel(size_t x, size_t y, uint8_t* out);
    void writeToFile(const char* fileName);

    static PPM loadFromFile(const char* fileName);
private:
    size_t mWidth;
    size_t mHeight;
    uint8_t* mData;
};

}

#endif