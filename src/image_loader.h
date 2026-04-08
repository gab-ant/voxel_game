#pragma once
#include <string>

#include "image.h"

using std::string;

class ImageLoader
{
    public:
	ImageLoader();

	// I/O?
	Image loadImage(string path);

    private:
};
