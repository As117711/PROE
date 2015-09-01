#include "simpleprocessing.h"
#include <vector>
#include <algorithm>

using namespace std;

bool SimpleProcessing::smoothing(unsigned char *rgb_pixels, int image_width, int image_height, int bytes_per_pixel)
{
    if (image_width < 1 || image_height < 1 || image_width > 10000 || image_height > 10000)
        return false;

    int bpp = bytes_per_pixel;
    vector<float> grayscale(image_width * image_height);
    vector<float> smoothed(image_width * image_height, 0.0f);

    for (int i = 0; i < image_height * image_width; i++)
        grayscale[i] = rgb_pixels[i * bpp] * 0.33f + rgb_pixels[i * bpp + 1] * 0.33f + rgb_pixels[i * bpp + 2] * 0.33f;

    const int radius = 5;
    const int n_shifts = (2 * radius + 1)*(2 * radius + 1);

    int shift_x[n_shifts];
    int shift_y[n_shifts];


    int i = 0;
    for (int x = -radius; x <= radius; x++)
        for (int y = -radius; y <= radius; y++)
        {
            shift_x[i] = x;
            shift_y[i] = y;
            i++;
        }

    int pos, pos2;
    for (int x = radius; x < image_width- radius; x++)
        for (int y = radius; y < image_height - radius; y++)
        {
            pos = y*image_width + x;
            for (int i = 0; i < n_shifts; i++)
            {
                pos2 = (y + shift_y[i]) * image_width + x + shift_x[i];
                float D = grayscale[pos2];
                smoothed[pos] += D;
            }
            smoothed[pos] /= n_shifts;
        }

    for (int i = 0; i < image_height * image_width; i++)
    {
        int val = static_cast<int>(smoothed[i]);
        if (val > 255)
            val = 255;
        rgb_pixels[i * bpp] = val;
        rgb_pixels[i * bpp + 1] = val;
        rgb_pixels[i * bpp + 2] = val;
    }
    return true;
}

bool SimpleProcessing::convertToGrayscale(unsigned char *rgb_pixels, int image_width, int image_height, int bytes_per_pixel)
{
    if (image_width < 1 || image_height < 1 || image_width > 10000 || image_height > 10000)
        return false;

    int bpp = bytes_per_pixel;
    int val;

    for (int i = 0; i < image_height * image_width; i++)
    {
        val = static_cast<int>(rgb_pixels[i * bpp] * 0.33 + rgb_pixels[i * bpp + 1] * 0.33 + rgb_pixels[i * bpp + 2] * 0.33);
        if (val>255)
            val = 255;

        rgb_pixels[i * bpp] = val;
        rgb_pixels[i * bpp + 1] = val;
        rgb_pixels[i * bpp + 2] = val;
    }
    return true;
}

bool SimpleProcessing::edgeDetection(unsigned char *rgb_pixels, int image_width, int image_height, int bytes_per_pixel)
{
    if (image_width < 1 || image_height < 1 || image_width > 10000 || image_height > 10000)
        return false;

    int bpp = bytes_per_pixel;

    vector<float> grayscale(image_width * image_height);
    vector<float> edges(image_width * image_height, 0.0f);

    for (int i = 0; i < image_height * image_width; i++)
        grayscale[i] = rgb_pixels[i * bpp] * 0.33f + rgb_pixels[i * bpp + 1] * 0.33f + rgb_pixels[i * bpp + 2] * 0.33f;

    int pos;
    float max_G = 1;
    for (int x = 1; x < image_width-1; x++)
        for (int y = 1; y < image_height - 1; y++)
        {
            pos = y*image_width + x;
            float Dx = (grayscale[pos + 1] - grayscale[pos - 1]) * 0.5f;
            float Dy = (grayscale[pos + image_width] - grayscale[pos - image_width]) * 0.5f;
            float D = sqrt(Dx * Dx + Dy * Dy);
            edges[pos] = D;
            max_G = max(max_G, D);
        }

    for (int i = 0; i < image_height * image_width; i++)
    {
        int val = static_cast<int>((edges[i] / max_G) * 255.0f);
        if (val > 10)
            val = 255;

        rgb_pixels[i * bpp] = val;
        rgb_pixels[i * bpp + 1] = val;
        rgb_pixels[i * bpp + 2] = val;
    }
    return true;
}
