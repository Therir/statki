#pragma once
#include <SFML/Graphics.hpp>
#include "plansza.h"
#include "statek.h"
class silnik
{
public:
	silnik();
	~silnik();
	sf::RenderWindow window;
	bool running;
	bool ustawiony;
	bool fazaUstawiania();
	bool inicjalizacja();
private://todo:moze przeniesc do klasy gracz
	plansza P1; //gracz 1
	plansza P2; //gracz 2
	plansza O1; //plansza przeciwnika gracza 1
	plansza O2; //plansza przeciwnika gracza 2
};

