



#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include "imageloader.h"
//#include "glclass.h"
#include "imageloader.h"

#include <GL/glu.h>
#include <GL/gl.h>
//#include <GL/freeglut.h>
//#include <GL/glcorearb.h>
#include <GL/glx.h>




using namespace std;

 fstream file;
    //unsigned long size;

       // wxMessageBox("OK", _("Start TEXTURE ID..."));
    unsigned long i;
    unsigned short int planes;
    unsigned short int bpp;
    char temp;
char* pixels2;
int size;
int bytesPerRow;

Image::Image(char* ps, int w, int h) : pixels(ps), width(w), height(h) {

}

Image::~Image() {

}

namespace {
	//Converts a four-character array to an integer, using little-endian form
	int toInt(const char* bytes) {
		return (int)(((unsigned char)bytes[3] << 24) |
			((unsigned char)bytes[2] << 16) |
			((unsigned char)bytes[1] << 8) |
			(unsigned char)bytes[0]);
	}

	//Reads the next four bytes as an integer, using little-endian form
	int readInt(fstream &input) {
		char buffer[4];
		input.read(buffer, 4);
		return toInt(buffer);
	}
}

Image* loadBMP(const char* filename, Image* image) {

    file.open(filename);
    file.seekg(10, std::ios::cur);
    int dataOffset = readInt(file);
    int headerSize = readInt(file);
	int width = readInt(file);
	int height = readInt(file);

	//Read the data
	bytesPerRow = ((width * 3 + 3) / 4) * 4 - (width * 3 % 4);
	size = bytesPerRow*height;
	char* pixels = new char[size];
	file.seekg(dataOffset, ios_base::beg);
	file.read(pixels, size);
	file.close();

	pixels2 = new char[width * height * 3];
	for(int y = 0; y < height; y++) {
		for(int x = 0; x < width; x++) {
			for(int c = 0; c < 3; c++) {
				pixels2[3*(width*y + x) + c] = pixels[bytesPerRow*y + 3*x + (2 - c)];
			}
		}
	}
	delete[] pixels;
	return new Image(pixels2, width, height);

        //wxMessageBox("OK", _("GOT TEXTURE ID..."));

}

GLuint loadTextureFromImage(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId);
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,
		0,
		GL_RGB,
		image->width, image->height,
		0,
		GL_RGB,
		GL_UNSIGNED_BYTE,
		image->pixels);
	return textureId;
}
