#include "common.h"

#define SWIDTH 800
#define SHEIGHT 600

#define WIDTH_WINDOW 960
#define HEIGHT_WINDOW 540

#define INCREMENT_LINE 0.2
#define RADIUS 200

void DrawLine(int _x1, int _y1, int _x2, int _y2, sf::Color _color, sf::Image& _image, sf::Image& _masque)
{
	int ecartX = _x2 - _x1;
	int ecartY = _y2 - _y1;
	sf::Color color = sf::Color::Transparent;


	if (ecartX == 0) //Ligne verticale, pas de division par zéro
	{
		if (ecartY > 0) //Ligne allant vers le bas
		{
			for (int j = 0; j < ecartY; j++)
			{
				sf::Vector2i finalPos = sf::Vector2i(_x1, j + _y1);

				if (finalPos.x >= 0 && finalPos.x < SWIDTH //Test d'obstacle
					&& finalPos.y >= 0 && finalPos.y < SHEIGHT
					&& _masque.getPixel(finalPos.x, finalPos.y).a != 0)
				{
					color = sf::Color::Black;
				}
				DrawPixel(_image, finalPos, color);
			}
		}
		else //Ligne allant vers le haut
		{
			for (int j = 0; j > ecartY; j--)
			{
				sf::Vector2i finalPos = sf::Vector2i(_x1, j + _y1);
				if (finalPos.x >= 0 && finalPos.x < SWIDTH //Test d'obstacle
					&& finalPos.y >= 0 && finalPos.y < SHEIGHT
					&& _masque.getPixel(finalPos.x, finalPos.y).a != 0)
				{
					color = sf::Color::Black;
				}
				DrawPixel(_image, finalPos, color);
			}
		}
	}
	else //Ligne en pente
	{
		float pente = ecartY / (float)ecartX;

		if (pente > -1 && pente < 1) //Ligne à peu près plate
		{
			if (ecartX > 0) //Ligne allant vers la droite
			{
				for (int i = 0; i < ecartX; i++)
				{
					sf::Vector2i finalPos = sf::Vector2i(i + _x1, pente * i + _y1);

					if (finalPos.x >= 0 && finalPos.x < SWIDTH //Test d'obstacle
						&& finalPos.y >= 0 && finalPos.y < SHEIGHT
						&& _masque.getPixel(finalPos.x, finalPos.y).a != 0)
					{
						color = sf::Color::Black;
					}
					DrawPixel(_image, finalPos, color);
				}
			}
			else //Ligne allant vers la gauche
			{
				for (int i = 0; i > ecartX; i--)
				{
					sf::Vector2i finalPos = sf::Vector2i(i + _x1, pente * i + _y1);
					if (finalPos.x >= 0 && finalPos.x < SWIDTH //Test d'obstacle
						&& finalPos.y >= 0 && finalPos.y < SHEIGHT
						&& _masque.getPixel(finalPos.x, finalPos.y).a != 0)
					{
						color = sf::Color::Black;
					}
					DrawPixel(_image, finalPos, color);
				}
			}

		}
		else //Ligne plutôt verticale
		{
			if (ecartY > 0) //Ligne allant vers le bas
			{
				for (int j = 0; j < ecartY; j++)
				{
					sf::Vector2i finalPos = sf::Vector2i(j / pente + _x1, j + _y1);
					if (finalPos.x >= 0 && finalPos.x < SWIDTH //Test d'obstacle
						&& finalPos.y >= 0 && finalPos.y < SHEIGHT
						&& _masque.getPixel(finalPos.x, finalPos.y).a != 0)
					{
						color = sf::Color::Black;
					}
					DrawPixel(_image, finalPos, color);
				}
			}
			else //Ligne allant vers le haut
			{
				for (int j = 0; j > ecartY; j--)
				{
					sf::Vector2i finalPos = sf::Vector2i(j / pente + _x1, j + _y1);
					if (finalPos.x >= 0 && finalPos.x < SWIDTH //Test d'obstacle
						&& finalPos.y >= 0 && finalPos.y < SHEIGHT
						&& _masque.getPixel(finalPos.x, finalPos.y).a != 0)
					{
						color = sf::Color::Black;
					}
					DrawPixel(_image, finalPos, color);
				}
			}
		}
	}
}

void DrawLineSimple(sf::Image& _image, int _x1, int _y1, int _x2, int _y2, sf::Color _color)
{
	int ecartX = _x2 - _x1;
	int ecartY = _y2 - _y1;

	if (ecartX == 0) //Ligne verticale, pas de division par zéro
	{
		if (ecartY > 0) //Ligne allant vers le bas
		{
			for (int j = 0; j < ecartY; j++)
			{
				DrawPixel(_image, sf::Vector2i(_x1, j + _y1), _color);
			}
		}
		else //Ligne allant vers le haut
		{
			for (int j = 0; j > ecartY; j--)
			{
				DrawPixel(_image, sf::Vector2i(_x1, j + _y1), _color);
			}
		}
	}
	else //Ligne en pente
	{
		float pente = ecartY / (float)ecartX;

		if (pente > -1 && pente < 1) //Ligne à peu près plate
		{
			if (ecartX > 0) //Ligne allant vers la droite
			{
				for (int i = 0; i < ecartX; i++)
				{
					DrawPixel(_image, sf::Vector2i(i + _x1, pente * i + _y1), _color);
				}
			}
			else //Ligne allant vers la gauche
			{
				for (int i = 0; i > ecartX; i--)
				{
					DrawPixel(_image, sf::Vector2i(i + _x1, pente * i + _y1), _color);
				}
			}

		}
		else //Ligne plutôt verticale
		{
			if (ecartY > 0) //Ligne allant vers le bas
			{
				for (int j = 0; j < ecartY; j++)
				{
					DrawPixel(_image, sf::Vector2i(j / pente + _x1, j + _y1), _color);
				}
			}
			else //Ligne allant vers le haut
			{
				for (int j = 0; j > ecartY; j--)
				{
					DrawPixel(_image, sf::Vector2i(j / pente + _x1, j + _y1), _color);
				}
			}
		}
	}


}

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH_WINDOW, HEIGHT_WINDOW), "Light 2D");

	sf::Image image;
	sf::Sprite sprite;
	sf::Texture texture;
	image.create(WIDTH_WINDOW, HEIGHT_WINDOW);
	texture.loadFromImage(image);
	sprite.setTexture(texture);

	sf::Sprite player = LoadSprite("../Assets/front.bmp", true);
	sf::Sprite background = LoadSprite("../Assets/grandepelouse.png",false);
	sf::Sprite light = LoadSprite("../Assets/lumiere.png", true);
	background.setScale(1.3,1.3);

	sf::Image imageMasque;
	sf::Sprite spriteMasque;
	sf::Texture textureMasque;

	imageMasque.loadFromFile("../Assets/masque.png");
	textureMasque.loadFromImage(imageMasque);
	spriteMasque.setTexture(textureMasque);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		sf::Vector2f posMouse = sf::Vector2f(sf::Mouse::getPosition(window));
		bool m_end = false;

		for (float i = 0; i < 90; i+= INCREMENT_LINE)
		{
			DrawLine(posMouse.x, posMouse.y, posMouse.x + cos(i) * RADIUS, posMouse.y + sin(i) * RADIUS, sf::Color::Transparent, image, imageMasque);
		}

		texture.update(image);
		player.setPosition(posMouse);
		light.setPosition(posMouse);

        window.clear(sf::Color::Green);

		window.draw(background);
		window.draw(spriteMasque);
		window.draw(sprite);
		window.draw(spriteMasque);
		window.draw(light);
		window.draw(player);

		window.display();  
    }


}
