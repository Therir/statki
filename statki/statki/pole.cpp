#include "stdafx.h"
#include "pole.h"
#include "Statek.h"
#include "Sprites.h"
#include "iostream"
#include <utility>


pole::pole()
{
	trafienie = false;
	pudlo = false;
	xpoz = 0;
	ypoz = 0;
	sprite = wszystkieSprites.poleSprite;
	this->mStatek = NULL; //pokazuje czy statek jest na polu - domyslnie nie
}


pole::~pole()
{
}

bool pole::czyTrafiony()
{
	return trafienie;
}

bool pole::czyPudlo()
{
	return pudlo;
}

void pole::strzal()
{
	trafienie = true;
	if (this->czyStatek()) {
		pudlo = false;
		mStatek->trafiony();
		sprite = wszystkieSprites.trafionySprite;
	}
	else {
		pudlo = true;
		sprite = wszystkieSprites.pudloSprite;
	}
}

bool pole::czyStatek()
{
	if (mStatek != NULL) return true;
	else return false;
}

void pole::ustawPozycje(int x, int y, bool gotowe)
{
	xpoz = x;
	ypoz = y;



}

std::pair<int, int> pole::zwrocPozycje()
{
	return std::pair<int, int>(xpoz, ypoz);
}

bool pole::zatopiony()
{
	if (mStatek != NULL) {
		return (mStatek->czyZatopiony());

	}
	else {
		return false;
	}
}

void pole::umiescStatek(Statek * nowy)
{
	if (mStatek == NULL) {
		this->mStatek = nowy;
		sprite = wszystkieSprites.statekSprite;
	}
	else {
		std::cout << "Na tym polu juz jest statek";
	}
}



void pole::usunStatek()
{
	this->mStatek = NULL;
	sprite = wszystkieSprites.poleSprite;
}

Statek * pole::zwrocStatek()
{
	return this->mStatek;
}

void pole::drawPole(sf::RenderWindow & w,int pozX, int pozY)
{
	
	sprite.setPosition(this->xpoz*59+10+pozX,this->ypoz*43+ 10+pozY);
	w.draw(sprite);
}
