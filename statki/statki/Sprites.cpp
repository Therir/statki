#include "stdafx.h"
#include "Sprites.h"


Sprites::Sprites()
{
	trafionyTexture.loadFromFile("pole_trafione.png");
	pudloTexture.loadFromFile("pole_pudlo.png");
	statekTexture.loadFromFile("statek.png");
	poleTexture.loadFromFile("pole.png");
	planszaTexture.loadFromFile("grid.png");

	trafionySprite.setTexture(trafionyTexture);
	pudloSprite.setTexture(pudloTexture);
	statekSprite.setTexture(statekTexture);
	poleSprite.setTexture(poleTexture);
	planszaSprite.setTexture(planszaTexture);

}


Sprites::~Sprites()
{
}
