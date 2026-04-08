#include "image.h"

Image::Image(int width, int height, unsigned char *data)
{
    this->width = width;
    this->height = height;
    this->data = data;
}
