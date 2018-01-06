// statki.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <SFML\Graphics.hpp>
#include <SFML\Window.hpp>
#include "plansza.h"
#include "pole.h"
#include <iostream>
int main()
{
	pole K;
	plansza P1;
	plansza O1;
	Statek S1(1);
	float dx;
	float dy;
	bool ruch = false;

	sf::Event event;
	sf::RenderWindow window;

	window.create(sf::VideoMode(1200, 600), "statki");
	//K.drawPole(window);
	//P1.drawPlansza(window, 0, 0);
	//O1.drawPlansza(window, 600, 0);

	//P1.drawPlansza(window, 0, 0);
	//P1.drawWybor(window, 10, 500);

	S1.sprite.setColor(sf::Color::Blue);
	S1.sprite.setPosition(600, 300);
	for (int i = 0; i < 10; i++) {
		P1.ustawPozycjeSprite(i, 59 + 100 * i, 500);
	}
	int n = 0;
	while (true)
	{
		
		sf::Vector2i pozycjaMyszki = sf::Mouse::getPosition(window);
		//window.clear(sf::Color::Black);
		window.pollEvent(event);
		if (event.type == sf::Event::Closed) {
			window.close();
			break;
		}
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.key.code == sf::Mouse::Left) {
				for(int i = 0; i <10; i++){
					if (P1.zwrocSprite(i).getGlobalBounds().contains(pozycjaMyszki.x, pozycjaMyszki.y)) {
						ruch = true;
						n = i;
						dx = pozycjaMyszki.x - P1.zwrocSprite(i).getPosition().x;
						dy = pozycjaMyszki.y - P1.zwrocSprite(i).getPosition().y;
						std::cout << "\ndx="<< P1.zwrocSprite(i).getPosition().x;
						std::cout << "\ndy="<< P1.zwrocSprite(i).getPosition().y;
						//std::cout << i;
						//std::cout << n;
					}
				}
			}
		}

		if (event.type == sf::Event::MouseButtonReleased) {
			if (event.key.code == sf::Mouse::Left) {
				ruch = false;
			}
		}
		//std::cout << "test n=" << n;
		if (ruch) {
			P1.ustawPozycjeSprite(n, pozycjaMyszki.x - dx, pozycjaMyszki.y - dy);
			std::cout << "\nPo odkliknieciu" << pozycjaMyszki.x - dx << " " << pozycjaMyszki.y - dy;
		}

		window.clear();
		
		P1.drawPlansza(window, 0, 0);
		for (int i = 0; i < 10; i++) {
			window.draw(P1.zwrocSprite(i));
		}
		//P1.drawWybor(window,10,500);
		std::cout<<"\nP1.zwrocSprite.getposition= "<< P1.zwrocSprite(n).getPosition().x;
		//window.draw(S1.sprite);
		
		window.display();
	}
	//window.clear();
	
	
    return 0;
}

