#pragma once
#include "pole.h"
#include "statek.h"
#include "Sprites.h"
#include <SFML/Graphics.hpp>
class plansza
{
public:
	plansza();
	~plansza();
	bool ustawStatek(int wiersz, int kolumna, int num); //ustawia statek o numerze spod zmiennej num na planszy w miejscu wierszxkolumna
	//bool zmienPozycje(int wiersz, int kolumna, int nWiersz, int nKolumna);
	bool sprawdzOkolice(int wiersz, int kolumna, int num, Statek * st);//sprawdza czy na polach w okol tego gdzie bedzie statek nie ma innych statkow
	bool czyWgranicach(int wiersz, int kolumna, int i, int j);//sprawdza czy statek bedzie w granicach planszy
	bool czyKoniec();
	bool czyTrafiony(int wiersz, int kolumna);//sprawdza czy dane pole bylo juz trafione
	bool czyStatek(int wiersz, int kolumna);//sprawdza czy dane pole posiada statek
	bool zmienMiejsce(int wiersz, int kolumna, int nWiersz, int nKolumna);
	

	void strzal(int wiersz, int kolumna);//"strzela" w okreslone miejsce
	void strzal(pole *); //strzela w wybrane pole
	pole * zwrocPole(int wiersz, int kolumna);//zwraca wybrane pole
	Statek zwrocStatek(int num);//zwraca wybrany statek

	sf::Sprite zwrocSprite(int num);
	void ustawPozycjeSprite(int num, int pozX, int pozY);

	void drawPlansza(sf::RenderWindow &w, int pozX, int pozY);
	void drawWybor(sf::RenderWindow &w, int pozX, int pozY);

	pole * poleNad(pole*);
	pole * polePod(pole*);
	pole * poleLewe(pole*);
	pole * polePrawe(pole*);

private:
	pole P[10][10];
	Statek S[10];
	bool gotowe;
	bool puste;
};
