#include "color.h"
#include "vec3.h"
#include "ray.h"
#include <iostream>

// See "Ray Tracing in One Weekend" by Shirley et al.

color ray_color(const ray& r) {
    // simple gradient
    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5 * (unit_direction.y() + 1.0);
    return (1.0-a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0); // from white to blue ish
}

int main() {
    // image
    auto aspect_ratio = 16.0 / 9.0;
    int image_width = 400;

    // calculate height from width and aspect ratio, ensure it is valid (at least 1)
    int image_height = int(image_width / aspect_ratio);
    image_height = image_height < 1 ? 1 : image_height;

    // camera and viewport - note we dont use aspect_ratio to compute viewport_width because aspect_ratio is ideal
    double focal_length = 1.0;
    double viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(image_width) / image_height);
    point3 camera_center = point3(0, 0, 0);

    // calculate vectors across the horizontal and down vertical viewport edges
    vec3 viewport_u = vec3(viewport_width, 0, 0); // horizontal
    vec3 viewport_v = vec3(0, -viewport_height, 0); // vertical
    // calculate the deltas from pixel to pixel (spacing)
    vec3 pixel_delta_u = viewport_u / image_width;
    vec3 pixel_delta_v = viewport_v / image_height;

    // calculate position of upper-left pixel
    auto viewport_upper_left = camera_center
                            - vec3(0, 0, focal_length)
                            - viewport_u/2
                            - viewport_v/2;
    auto pixel00_loc = viewport_upper_left + 0.5*(pixel_delta_u + pixel_delta_v);

    // render
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush; // progress
        for (int i = 0; i < image_width; i++) {
            //
            vec3 pixel_center = pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v);
            vec3 ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);

            color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
        }
    }
    std::clog << "\rDone.                 \n";
    // redirect stdout to a ppm file using '>' as usual
}