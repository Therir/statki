#include "stdafx.h"
#include "plansza.h"
#include <iostream>


plansza::plansza()
{
	S[0].ustawRozmiar(4);
	S[1].ustawRozmiar(3);
	S[2].ustawRozmiar(3);
	S[3].ustawRozmiar(2);
	S[4].ustawRozmiar(2);
	S[5].ustawRozmiar(2);
	for (int i = 6; i <= 10; i++) {
		S[i].ustawRozmiar(1);
	}
	gotowe = true;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			this->P[i][j].ustawPozycje(j, i, gotowe);
		}
	}
}


plansza::~plansza()
{
}

bool plansza::ustawStatek(int wiersz, int kolumna, int num)
{
	if (!(this->S[num].czyUstawiony())) {
		if (sprawdzOkolice(wiersz, kolumna, num)) {
			if (S[num].czyPoziomy()) {
				for (int i = 0; i < S[num].zwrocRozmiar(); i++) {//petla do ustawiania statku, zaznacza ze statek znajduje sie na odpowiednich polach
					S[num].ustawPozycje(wiersz, kolumna);
					P[wiersz][kolumna + i].bStatek = true;
					S[num].ustawPola(i, wiersz, kolumna);
					S[num].ustaw();
				}
				return true;
			}
			else {
				for (int i = 0; i < S[num].zwrocRozmiar(); i++) {
					S[num].ustawPozycje(wiersz, kolumna);
					P[wiersz + i][kolumna].umiescStatek(true);
					S[num].ustawPola(i, wiersz, kolumna);
					S[num].ustaw();
				}
				return true;
			}
			this->S[num].ustawPozycje(wiersz, kolumna);
		}
		else {
			return false;
		}
	}
	else return false;
}

bool plansza::sprawdzOkolice(int wiersz, int kolumna, int num)
{
	if (this->S[num].czyPoziomy()) {
		for (int i = -1; i < 2; i++) {//od -1 bo musi sprawdzic pole u gory, pole ktore jest wybrane i pole u dolu
			for (int j = -1; j < this->S[num].zwrocRozmiar() + 1; j++) {//analogicznie jak petla wyzej, tylko sprawdza po dlugosci statku czy zadne pole nie jest zajete
				if (czyWgranicach(wiersz, kolumna, i, j)) {
					if (!(czyStatek(wiersz + i, kolumna + j))) {
						this->puste = true;
					}
					else {
						this->puste = false;
					}
					if (!(this->puste)) { //jezeli nie jest puste to od razu wyrzuca mozliwosc umieszczenia statku
						return false;
					}

				}
				else {
					//std::cout << "poza granicami";
					return false;
				}
			}
		}
	}
	else {//tak samo jak wyzej tylko jesli statek jest pionowy
		for (int i = -1; i < this->S[num].zwrocRozmiar() + 1; i++) {
			for (int j = -1; j < 2; j++) {
				if (czyWgranicach(wiersz, kolumna, i, j)) {
					if (wiersz + i > 9 || wiersz + i < 0) {
						if (kolumna + j > 9 || kolumna + j < 0) {
							this->puste = true;
							std::cout << "Jestem tu";
						}
					}
					else if (!(czyStatek(wiersz + i, kolumna + j))) {//jezeli nie ma statku (bstatek = false) to zaprzeczeczenie czyli wchodzi do srodka
						std::cout << "\nWiersz w petli: " << wiersz + i << "kolumna w petli: " << kolumna + j << "bstatek" << czyStatek(wiersz + i, kolumna + i);
						this->puste = true;
					}
					else {
						this->puste = false; 
					}
					if (!(this->puste)) {
						return false;
					}

				}
				else {
					return false;
				}
			}

		}
	}
}

bool plansza::czyWgranicach(int wiersz, int kolumna, int i, int j)
{
	if (wiersz + i > 9 && kolumna + j < 0 ) {
		return true;
	}
	if (wiersz + i > 9 &&  kolumna + j > 9) {
		return true;
		
	}
	if (wiersz + i < 0 && kolumna + j < 0 ) {
		return true;
	}
	if (wiersz + i < 0 && kolumna + j > 9) {
		return true;
	}
	if (wiersz + i > 9 && kolumna + j >= 0 && kolumna + j <= 9) {
		return true;
	}
	if (wiersz + i < 0 && kolumna + j >= 0 && kolumna + j <= 9) {
		return true;
	}

	if (wiersz + i >= 0 && wiersz + i <= 9 && kolumna + j > 9 ){
		return true;
	}
	if (wiersz + i >= 0 && wiersz + i <= 9 && kolumna + j < 0) {
		return true;
	}

	if (wiersz + i >= 0 && wiersz + i <= 9 && kolumna + j >= 0 && kolumna + j <= 9) {
		return true;
	}
	else{
		return false; 
	}
	
}

bool plansza::czyKoniec()
{
	bool koniec = false;
	int l = 0;
	for (int i = 0; i < 10; i++) {
		if (this->S[i].czyZatopiony())
			l++;
	}
	if (l == 10) {
		koniec = true;
	}
	return koniec;
}

bool plansza::czyTrafiony(int wiersz, int kolumna)
{
	return this->P[wiersz][kolumna].czyTrafiony(); //czy trafiony z pole.h
	
}

bool plansza::czyStatek(int wiersz, int kolumna)
{
	return this->P[wiersz][kolumna].czyStatek();
}

bool plansza::zmienMiejsce(int wiersz, int kolumna, int nWiersz, int nKolumna)
{
	return false;
}

void plansza::strzal(int wiersz, int kolumna)
{
	this->P[wiersz][kolumna].strzal();
	if (this->P[wiersz][kolumna].zatopiony()) {
		Statek * nStatek;
		nStatek = this->P[wiersz][kolumna].zwrocStatek();//zwraca obiekt statek ktory znajduje sie na danym polu
		wiersz = nStatek->zwrocPozycje().first;//zwraca wiersz w jakiej zaczyna sie statek
		kolumna = nStatek->zwrocPozycje().second;//zwraca kolumne w jakiej zaczyna sie statek
		if (nStatek->czyPoziomy()) {
			for (int i = -1; i < 2; i++) {
				for (int j = -1; j < nStatek->zwrocRozmiar() + 1; j++) {
					if (czyWgranicach(wiersz, kolumna, i, j)) {
						this->P[wiersz + i][kolumna + j].strzal();
					}
				}
			}
		}
		else {
			for (int i = -1; i < nStatek->zwrocRozmiar() + 1; i++) {
				for (int j = -1; j < 2; j++) {
					if (czyWgranicach(wiersz, kolumna, i, j)) {
						this->P[wiersz + i][kolumna + j].strzal();

					}
				}
			}
		}
	}
}

void plansza::strzal(pole *)
{
}

pole plansza::zwrocPole(int wiersz, int kolumna)
{
	return this->P[wiersz][kolumna];
}

Statek plansza::zwrocStatek(int num)
{
	return S[num];
}

sf::Sprite plansza::zwrocSprite(int num)
{
	return S[num].sprite;
}

sf::Sprite plansza::zwrocSpritePola(int i, int j)
{
	return P[i][j].sprite;
}

void plansza::ustawPozycjeSprite(int num, int pozX, int pozY)
{
	this->S[num].sprite.setPosition(pozX, pozY);
}

void plansza::drawPlansza(sf::RenderWindow &w,int pozX, int pozY)
{
	for (int i = 0; i < 10; i++) {
		
		for (int j = 0; j < 10; j++) {
			this->P[i][j].drawPole(w,pozX,pozY);
		}
	}
}

void plansza::drawWybor(sf::RenderWindow & w, int pozX, int pozY)
{
	for (int i = 0; i < 10; i++) {
		this->S[i].drawStatek(w, i*100, pozY);
	}
}

pole * plansza::poleNad(pole *)
{
	return nullptr;
}

pole * plansza::polePod(pole *)
{
	return nullptr;
}

pole * plansza::poleLewe(pole *)
{
	return nullptr;
}

pole * plansza::polePrawe(pole *)
{
	return nullptr;
}
