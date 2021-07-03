/**
 * @file Utils.cpp
 * 
 * @brief The code for the Utils functions
 * 
 * @author DePianoman, camden314
 */

#include "Utils.h"
#include <tchar.h>

/**
 * Creates a CCSprite with given image data
 * 
 * @param data The data to create the Sprite with
 * 
 * @return The CCSprite from the data
 */
CCSprite* Utils::createSprite(unsigned char data[]) {

	// Create a new CCImage using the image data
	CCImage *img = new CCImage();
	img->initWithImageData(&data, sizeof(data), CCImage::kFmtPng);
	
	// Create a CCTexture2D from the CCImage
	CCTexture2D *texture = new CCTexture2D();
	texture->initWithImage(img);

	// Create a CCSprite from the CCTexture2D and return
	CCSprite* sprite = CCSprite::createWithTexture(texture);
	return sprite;
}

/**
 * Creates a CCSprite with given image file, or the data if the image doesn't exist
 * 
 * @param data The data to create the Sprite with
 * @param imgName The filename of the image to use
 * 
 * @return The CCSprite from the data
 */
CCSprite* Utils::createSprite(unsigned char data[], const char* imgName) {

	// Define variables to be used later
	CCImage *img = new CCImage();
	FILE* imageFile;

	// If the file exists then create the CCImage using the file
	if (fopen_s(&imageFile, imgName, "r") == 0) {
		img->initWithImageFileThreadSafe(imgName);
	} // Otherwise create the CCImage using the image data
	else {
		img->initWithImageData(&data, sizeof(data), CCImage::kFmtPng);
	}
	
	// Create a CCTexture2D from the CCImage
	CCTexture2D *texture = new CCTexture2D();
	texture->initWithImage(img);

	// Create a CCSprite from the CCTexture2D and return
	CCSprite* sprite = CCSprite::createWithTexture(texture);
	return sprite;
}