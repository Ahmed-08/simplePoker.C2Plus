#pragma once
#include <string>
#include <iostream>

// ��������� ����� �������� ����� ����� � �����
struct card
{
	short number;
	std::string card_suit;
};

class Poker
{
public:
	// ����������� ��������� ���������� �����
	Poker(unsigned int nominals_);
	~Poker();

	// ������� ����� �� ������
	unsigned int& getNominals() { return this->nominals; }

	// ������� ����� �� ������
	short& getCountCards() { return this->count_cards; }

	// ��������� �����
	void shuffleCards();

	// ������� �����
	void game();

	// ��������� ����� �������
	short combinations(card* pl);

	// �������� �����
	void exchange(short* v);

private:
	unsigned int nominals;
	short count_cards;
	card* my_deck;
};


