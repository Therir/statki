#include "stdafx.h"
#include "Statek.h"
#include <utility>


Statek::Statek()
{
	this->rozmiar = 1;
	this->zycieStracone = 0;
	this->zatopiony = false;
	this->narysowany = false;
	this->poziomy = true;
	this->ustawiony = false;
	sprite = wszystkieSprites.statek1Sprite;
}

Statek::Statek(int rozmiar)
{
	
	this->zycieStracone = 0;
	this->zatopiony = false;
	this->narysowany = false;
	ustawRozmiar(rozmiar);

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
	ustawSprite();
		
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
	if (!(poziom)) {
		sprite.setOrigin(0, 0);
		sprite.setRotation(90);
	}
	else {
		sprite.setOrigin(0, 0);
		sprite.setRotation(0);
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
	return this->poziomy;
}

bool Statek::czyUstawiony()
{
	return this->ustawiony;
}

void Statek::trafiony()
{
	this->zycieStracone--;
	if (this->czyZatopiony() == true) {
		this->zatopiony = true;
	}
}



void Statek::drawStatek(sf::RenderWindow & w, int pozX, int pozY)
{
	
	sprite.setPosition(59 + pozX, 500);
	w.draw(sprite);
}

void Statek::ustawSprite()
{
		switch (this->rozmiar) {
	case 1:
		sprite = wszystkieSprites.statek1Sprite;
		break;
	case 2:
		sprite = wszystkieSprites.statek2Sprite;
		break;
	case 3:
		sprite = wszystkieSprites.statek3Sprite;
		break;
	case 4:
		sprite = wszystkieSprites.statek4Sprite;
	}
}

void Statek::ustawPola(int rozmiar, int wiersz, int kolumna)
{
		this->pola[rozmiar].first = wiersz;
		this->pola[rozmiar].second = kolumna;

}

void Statek::ustaw()
{
	this->ustawiony = true;
}
