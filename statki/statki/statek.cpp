#include "stdafx.h"
#include "Statek.h"
#include <utility>


Statek::Statek()
{
	this->rozmiar = 0;
	this->zycieStracone = 0;
	this->zatopiony = false;
	this->narysowany = false;
	sprite = wszystkieSprites.statekSprite;
}

Statek::Statek(int rozmiar)
{
	this->rozmiar = rozmiar;
	this->zycieStracone = 0;
	this->zatopiony = false;
	this->narysowany = false;
	sprite = wszystkieSprites.statekSprite;

}


Statek::~Statek()
{
}



bool Statek::czyZatopiony()
{
	if (this->zycieStracone >= this->rozmiar) return true;
	else return false;
}

void Statek::ustawRozmiar(int rozmiarNowy)
{
	this->rozmiar = rozmiarNowy;
}

void Statek::ustawPozycje(int wGora,int kGora) // w - wiersz, k - kolumna
{
	this->gora.first = wGora;
	this->gora.second = kGora;
	if (this->poziomy) {
		this->dol.first = gora.first + rozmiar - 1;
		this->dol.second = gora.second;
	}
	else {
		this->dol.first = this->gora.first;
		this->dol.second = this->gora.second + this->rozmiar -1;
	}
}

void Statek::ustawOrientacje(bool poziom)
{
	this->poziomy = poziom;
	if (this->poziomy) {
		sprite.setOrigin(0, 0);
		sprite.setRotation(90);
	}
}

std::pair<int, int> Statek::zwrocPozycje()
{
	return std::pair<int, int>(this->gora.first,this->gora.second);
}

int Statek::zwrocRozmiar()
{
	return this->rozmiar;
}



bool Statek::czyPoziomy()
{
	return poziomy;
}

void Statek::trafiony()
{
	this->zycieStracone--;
	if (this->czyZatopiony() == true) {
		this->zatopiony = true;
	}
}

void Statek::rysujStatek(sf::RenderWindow &w, bool gotowe, int rozmiar)
{
	//TODO:Zrobic druga klase tylko do rysowania w silniku, ta moze byc tylko do pierwszego ustawienia np w przyborniku jakims czy cos
	//TODO:Przeniesc do jakiegos ustaw sprite albo cos
	this->rozmiar = rozmiar;
	switch (this->rozmiar) {
	case 1:
		sprite = wszystkieSprites.pudloSprite;
		break;
	case 2:
		sprite = wszystkieSprites.poleSprite;
		break;
	case 3:
		sprite = wszystkieSprites.trafionySprite;
		break;
	case 4:
		sprite = wszystkieSprites.planszaSprite;
		break;
	}

	sprite.setScale(0.9f, 0.9f);
	w.draw(sprite);
}

void Statek::drawStatek(sf::RenderWindow & w, int pozX, int pozY)
{
	
	sprite.setPosition(59 + pozX, 500);
	w.draw(sprite);
}
