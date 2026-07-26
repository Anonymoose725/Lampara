#include <iostream>

// See "Ray Tracing in One Weekend" by Shirley et al.

int main() {
    // image
    int image_width = 256;
    int image_height = 256;

    // render
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        for (int i = 0; i < image_width; i++) {
            auto r = double(i) / (image_width - 1);
            auto g = double(j) / (image_height - 1);
            auto b = 0.0;

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);

            // pixels written in rows, written out left to row
            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
    return 0;
    // redirect stdout to a ppm file using '>' as usual
}