#pragma once
#include <utility>
#include "Sprites.h"
#include <SFML\Graphics.hpp>

class Statek
{
public:
	Statek();
	Statek(int rozmiar);
	~Statek();

	bool czyZatopiony();//sprawdza czy statek jest zatopiony
	void ustawRozmiar(int rozmiarNowy);//ustawia rozmiar statku
	void ustawPozycje(int wGora,int kGora);//ustawia pozycje statku na planszy
	void ustawOrientacje(bool poziom);
	std::pair <int, int> zwrocPozycje();
	int zwrocRozmiar();
	bool czyPoziomy();
	void trafiony();
	void rysujStatek(sf::RenderWindow &w, bool gotowe, int rozmiar);
	void drawStatek(sf::RenderWindow &w, int pozX, int pozY);
	sf::Sprite sprite;
	Sprites wszystkieSprites;
private:
	bool narysowany;
	bool zatopiony;
	bool poziomy; //zmienna okreslajaca czy statek jest poziomy czy pionowy
	int rozmiar; //zmienna okreslajaca rozmiar statku
	int zycieStracone;//zmienna okreslajaca ile razy zostal statek trafiony
	std::pair <int, int> gora, dol; //dwie pary zmiennych zawierajacych wspolrzedne gornej i dolnej krawedzi statku

};

