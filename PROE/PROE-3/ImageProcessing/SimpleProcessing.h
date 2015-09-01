#pragma once

class SimpleProcessing
{
public:
	SimpleProcessing() {}

	bool smoothing(unsigned char *rgb_pixels, int image_width, int image_height, int bytes_per_pixel);
	bool edgeDetection(unsigned char *rgb_pixels, int image_width, int image_height, int bytes_per_pixel);
	bool convertToGrayscale(unsigned char *rgb_pixels, int image_width, int image_height, int bytes_per_pixel);

};