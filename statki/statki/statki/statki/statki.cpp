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
	float dx, dxPola=0.0f, dy, dyPola=0.0f;
	bool ruch = false;
	bool ustaw = false;
	int test = 1;
	int row = 0, col = 0;


	sf::Event event;
	sf::RenderWindow window;

	window.create(sf::VideoMode(1200,900), "statki");
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
					for(int j=0; j<10; j++){
						if (P1.zwrocSprite(i).getGlobalBounds().contains(pozycjaMyszki.x, pozycjaMyszki.y)) {
							ruch = true;
							n = i;
							dx = pozycjaMyszki.x - P1.zwrocSprite(i).getPosition().x;
							dy = pozycjaMyszki.y - P1.zwrocSprite(i).getPosition().y;
							if (P1.zwrocSpritePola(i, j).getGlobalBounds().contains(pozycjaMyszki.x, pozycjaMyszki.y)) {
								dxPola = pozycjaMyszki.x - P1.zwrocSpritePola(i, j).getPosition().x;
								dyPola = pozycjaMyszki.y - P1.zwrocSpritePola(i, j).getPosition().y;
							}

							//std::cout << "\ndx="<< P1.zwrocSprite(i).getPosition().x;
							//std::cout << "\ndy="<< P1.zwrocSprite(i).getPosition().y;
							//std::cout << i;
							//std::cout << n;
						}
					}
				}
			}
		}

		if (event.type == sf::Event::MouseButtonReleased) {
			if (event.key.code == sf::Mouse::Left) {
				ruch = false;
				ustaw = true;
			}
		}
		if (ruch) {
			P1.ustawPozycjeSprite(n, pozycjaMyszki.x - dx, pozycjaMyszki.y - dy);
			//std::cout << "\nPo odkliknieciu statek" << pozycjaMyszki.x - dx<< " " << pozycjaMyszki.y - dy;
			//std::cout << "\nPo odkliknieciu pole:" << pozycjaMyszki.x - dxPola << " " << pozycjaMyszki.y - dyPola;
			col = (pozycjaMyszki.x - dx)/70;
			row = (pozycjaMyszki.y - dy)/70;
			
				
			//std::cout << "\nwiersz: " << (row /70);
			//std::cout << " kolumna: " << col / 70;
		}
		if (ustaw && !(P1.zwrocPole(row,col).czyStatek())) {//zaprzeczenie bo domyslnie jest false;
			//P1.ustawStatek(row, col, n,window);
			std::cout << "\nrow: " << row << "col: " << col;
			std::cout << "\nbstatek tam gdzie polozone PRZED:" << P1.zwrocPole(row, col).czyStatek();
			P1.ustawStatek(row, col, n);
			std::cout << "\nbstatek tam gdzie polozone PO: " << P1.zwrocPole(row, col).czyStatek();
			std::cout << "\nX PO: " << P1.zwrocPole(row, col).zwrocPozycje().first << "Y PO: " << P1.zwrocPole(row, col).zwrocPozycje().second;
			ustaw = false;
		}
			window.clear();
		
		P1.drawPlansza(window, 10, 0);
		for (int i = 0; i < 10; i++) {
			window.draw(P1.zwrocSprite(i));
		}
		//P1.drawWybor(window,10,500);
		//std::cout<<"\nP1.zwrocSprite.getposition= "<< P1.zwrocSprite(n).getPosition().x;
		//window.draw(S1.sprite);
		
		window.display();
	}
	//window.clear();
	
	
    return 0;
}

