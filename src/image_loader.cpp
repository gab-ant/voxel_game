#include "image_loader.h"
#include "image.h"
#include <iostream>

ImageLoader::ImageLoader()
{

}

Image ImageLoader::loadImage(string path) 
{
    std::cout << "Creating image\n";
    return Image(10, 10, new unsigned char[1]);
}
