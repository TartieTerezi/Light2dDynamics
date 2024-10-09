#ifndef COMMON__H
#define COMMON__H

#include <iostream>
#include <time.h>

#include "SFML/Window.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include <GL/glew.h>
#include <GL/wglew.h>
#include <GL/freeglut.h>
#include "SFML/OpenGL.hpp"

sf::Sprite LoadSprite(const std::string _path , bool);
void BlitSprite(sf::Sprite _sprite, float _posX, float _posY, float _angle, sf::RenderWindow& _window);
void DrawPixel(sf::Image& _image, sf::Vector2i _pos, sf::Color _color);


#endif
