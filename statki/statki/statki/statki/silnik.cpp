#include "stdafx.h"
#include "silnik.h"
#include <SFML/Graphics.hpp>


silnik::silnik()
{
	window.create(sf::VideoMode(800, 600), "Game");
	running = true;

}


silnik::~silnik()
{
}

bool silnik::fazaUstawiania()
{
	//P1.
	return false;
}

bool silnik::inicjalizacja()
{
	plansza P1;
	plansza O1;

	sf::Event event;
	sf::RenderWindow window;

	window.create(sf::VideoMode(1200, 600), "statki");
	//K.drawPole(window);
	P1.drawPlansza(window, 0, 0);
	O1.drawPlansza(window, 600, 0);
	window.display();
	while (true)
	{
		//window.clear(sf::Color::Black);
		window.pollEvent(event);
		if (event.type == sf::Event::Closed) {
			window.close();
			break;

		}
	}
	return false;
}


