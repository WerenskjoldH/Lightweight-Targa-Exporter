#pragma once
#include <iostream>

typedef unsigned __int8 u_int8;

// Remember Targa reads blue, green, red, alpha
struct pixel {
	u_int8 b;
	u_int8 g;
	u_int8 r;
	u_int8 a;
};

struct targaInfo {
private:
	u_int8 idLength;
	u_int8 colorMapType;
	u_int8 dataTypeCode;
	short int colorMapOrigin;
	short int colorMapLength;
	u_int8 colorMapDepth;
	short int x_origin;
	short int y_origin;
	u_int8 bitsPerPixel;
	u_int8 imageDescriptor;

public:
	pixel* data;
	short width;
	short height;

	targaInfo(short width, short height)
	{
		this->idLength = 0;
		this->colorMapType = 0;
		this->dataTypeCode = 2;
		this->colorMapOrigin = 0;
		this->colorMapLength = 0;
		this->colorMapDepth = 0;
		this->x_origin = 0;
		this->y_origin = 0;
		this->width = width;
		this->height = height;
		this->bitsPerPixel = 32;
		this->imageDescriptor = 0;

		this->data = (pixel*)malloc(width * height * sizeof(pixel));

		for (int y = 0; y < height; y++)
			for (int x = 0; x < width; x++)
			{
				this->data[y * width + x].b = 0;
				this->data[y * width + x].g = 0;
				this->data[y * width + x].r = 0;
				this->data[y * width + x].a = 0;
			}
	}

	void outputImage(char * fileName)
	{
		FILE *fileptr;


		if ((fileptr = fopen("output.tga", "w")) == NULL)
		{
			std::cout << "Error opening output file";

			exit(-1);
		}

		putc(idLength, fileptr);
		putc(colorMapDepth, fileptr);
		putc(dataTypeCode, fileptr);
		fwrite(&colorMapOrigin, sizeof(colorMapOrigin), 1, fileptr);
		fwrite(&colorMapLength, sizeof(colorMapLength), 1, fileptr);
		putc(colorMapDepth, fileptr);
		fwrite(&x_origin, sizeof(x_origin), 1, fileptr);
		fwrite(&y_origin, sizeof(y_origin), 1, fileptr);
		fwrite(&width, sizeof(width), 1, fileptr);
		fwrite(&height, sizeof(height), 1, fileptr);
		putc(bitsPerPixel, fileptr);
		putc(imageDescriptor, fileptr);

		for (int y = 0; y < height; y++)
			for (int x = 0; x < width; x++)
			{
				putc(data[y * width + x].b, fileptr);
				putc(data[y * width + x].g, fileptr);
				putc(data[y * width + x].r, fileptr);
				putc(data[y * width + x].a, fileptr);
			}

		fclose(fileptr);
	}
};

