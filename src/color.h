#ifndef LAMPARA_COLOR_H
#define LAMPARA_COLOR_H


#include "vec3.h"
#include <iostream>

using color = vec3;
//using colour = vec3;

void write_color(std::ostream& out, const color& pixel_color) { // writes a single pixel's colour to output stream
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // [0, 1] -> [0, 255]
    int rbyte = int(255.999 * r);
    int gbyte = int(255.999 * g);
    int bbyte = int(255.999 * b);

    // write pixel color comps to output stream
    out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
}

#endif //LAMPARA_COLOR_H