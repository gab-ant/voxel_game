#include<string>
#include<iostream>
#include<fstream>

#include "image.h"

namespace imageLoader {
    Image loadImage(std::string path)
    {
	// Prints should be replaced by proper logging
	std::cout << "Creating image\n";

	std::string line;
	std::ifstream file(path);
	if (file.is_open())
	{
	    while(std::getline(file, line))
	    {
		std::cout << line + '\n';
	    }
	    file.close();
	} 
	else std::cout << "Could not open texture image file" << '\n';

	return Image(10, 10, new unsigned char[1]);
    }
}
