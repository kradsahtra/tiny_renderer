#include "tga_image.h"

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);

void line(int x0, int y0, int x1, int y1, TGAImage &image, const TGAColor &color) {
    for (int t = 0; t < 100; t++) {
        int x = x0 * (100 - t) / 100 + x1 * t;
        int y = y0 * (100 - t) / 100 + y1 * t;
        image.set(x, y, color);
    }
}

int main(int argc, char **argv) {
    TGAImage image(100, 100, TGAImage::RGB);
    line(13, 20, 80, 40, image, white);
    image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
    image.write_tga_file("output.tga");
    return 0;
}