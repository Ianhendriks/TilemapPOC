#include "Texture.hpp"



Texture::Texture(SDL_Texture* texture, int width, int height) :
	_texture {texture},
	_width {width},
	_height{height} {}


SDL_Texture* Texture::texture() const
{
	return _texture;
}

void Texture::set_texture(SDL_Texture* texture)
{
	_texture = texture;
}

int Texture::width() const
{
	return _width;
}

void Texture::set_width(int width)
{
	_width = width;
}

int Texture::height() const
{
	return _height;
}

void Texture::set_height(int height)
{
	_height = height;
}



	
