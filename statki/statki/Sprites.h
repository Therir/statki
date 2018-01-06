#pragma once
#include <SFML\Graphics.hpp>
class Sprites
{
public:
	Sprites();
	sf::Sprite trafionySprite;
	sf::Sprite pudloSprite;
	sf::Sprite statekSprite;
	sf::Sprite poleSprite;
	sf::Sprite planszaSprite;

	~Sprites();
private:
	sf::Texture trafionyTexture;
	sf::Texture pudloTexture;
	sf::Texture statekTexture;
	sf::Texture poleTexture;
	sf::Texture planszaTexture;
};

