
#include "ppmlib/ppm.h"

#include <math.h>

using namespace ppmlib;

int main(int argc, const char** argv) {
    PPM input = PPM::loadFromFile(argv[1]);
    PPM output = PPM(input.getWidth() * 2, input.getHeight() * 2);

    uint8_t pixelValue[3];
    for (int i = 0; i < output.getHeight(); i++) {
        for (int j = 0; j < output.getWidth(); j++) {
            input.getPixel(j % input.getWidth(), i % input.getHeight(), pixelValue);
            output.setPixel(
                j, i,
                pixelValue[0], pixelValue[1], pixelValue[2]
            );
        }
    }

    output.writeToFile(argv[2]);
    return 0;
}
