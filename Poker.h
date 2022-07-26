#pragma once
#include <string>
#include <iostream>

// структура карта содержит номер карты и масть
struct card
{
	short number;
	std::string card_suit;
};

class Poker
{
public:
	// конструктор принимает количество фишек
	Poker(unsigned int nominals_);
	~Poker();

	// вернуть фишки по ссылке
	unsigned int& getNominals() { return this->nominals; }

	// вернуть карты по ссылке
	short& getCountCards() { return this->count_cards; }

	// размешать карты
	void shuffleCards();

	// раздать карты
	void game();

	// проверить карты играков
	short combinations(card* pl);

	// обменять карты
	void exchange(short* v);

private:
	unsigned int nominals;
	short count_cards;
	card* my_deck;
};


