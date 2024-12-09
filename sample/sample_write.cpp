#include "ppmlib/ppm.h"

using namespace ppmlib;

int main(int argc, const char** argv) {
    PPM p(256, 256);

    for (int i = 0; i < 256; i++) {
        for (int j = 0; j < 256; j++) {
            p.setPixel(
                j, i,
                i, j, 0
            );
        }
    }

    p.writeToFile(argv[1]);
    return 0;
}
