#include <iostream>
#include <utility>
#include "tga_image.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);

void line(int x0, int y0, int x1, int y1, TGAImage &image, const TGAColor &color) {
    bool steep = false;
    if (abs(x1 - x0) < abs(y1 - y0)) {
        steep = true;
        std::swap(x0, y0);
        std::swap(x1, y1);
    }

    int count = abs(x1 - x0);

    for (int t = 0; t < count; t++) {
        int x = x0 * (count - t) / count + x1 * t / count;
        int y = y0 * (count - t) / count + y1 * t / count;
        std::cout << "x: " << x << ", y: " << y << "\n";
        if (steep) {
            image.set(y, x, color);
        } else {
            image.set(x, y, color);
        }
    }
}

int main(int argc, char **argv) {
    TGAImage image(100, 100, TGAImage::RGB);
    line(13, 20, 80, 40, image, white);
    line(20, 13, 40, 80, image, red);
    line(80, 40, 13, 20, image, red);
    image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
    image.write_tga_file("output.tga");
    return 0;
}