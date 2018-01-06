#pragma once
#include "Statek.h"
#include "Sprites.h"
#include <utility>
class pole
{
public:
	pole();
	~pole();
	bool czyTrafiony();
	bool czyPudlo();
	void strzal();
	bool czyStatek();
	void ustawPozycje(int x, int y, bool gotowe);
	std::pair <int, int> zwrocPozycje(); 
	bool zatopiony();
	void umiescStatek(Statek * nowy);
	void usunStatek();
	Statek * zwrocStatek();
	Sprites wszystkieSprites;
	sf::Sprite sprite;
	void drawPole(sf::RenderWindow &w, int pozX, int pozY);
private:
	bool trafienie;
	bool pudlo;
	int xpoz, ypoz;
	Statek * mStatek;
};

