#pragma once

class Image
{
    public:
	int width;
	int height;

	unsigned char *data;

	Image(int width, int height, unsigned char *data);

    private:
};
