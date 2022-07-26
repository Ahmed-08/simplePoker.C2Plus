#include "Poker.h"

/*
* Простой классический покер с двумя игроками
*/

std::string suits_carts[]
{
	"clubs", "diamonds", "hearts", "spades"
};

card* player1 = new card[5];
card* player2 = new card[5];

Poker::Poker(unsigned int nominals_) :	nominals{nominals_},
										count_cards{ 52 },
										my_deck { new card[count_cards] }
{
	short k{ 0 }, num{ 2 };
	for (short i{ 0 }; i < 52; ++i)
	{
		if (i % 13 == 0)
		{
			num = 2;
			++k;
			if (k == 4) k = 0;
		}
		my_deck[i] = { num, suits_carts[k] };
		++num;
	}
}
Poker::~Poker() { delete[] my_deck; }

// случайным образом меням пару карт
// меням 52 раза
// 52 - количество карт
void Poker::shuffleCards()
{
	for (short i{ 0 }; i < this->count_cards; ++i)
	{
		int8_t num1 = rand() % 52;
		int8_t num2 = rand() % 52;
		std::swap(this->my_deck[num1], this->my_deck[num2]);
	}

	// переварачивам
	for (short i{ 0 }; i < this->count_cards / 2; ++i)
	{
		std::swap(this->my_deck[i], this->my_deck[count_cards-i-1]);
	}
}

// прверяем комбинации
short Poker::combinations(card* pl)
{
	if (pl[0].card_suit == pl[1].card_suit && \
		pl[1].card_suit == pl[2].card_suit && \
		pl[2].card_suit == pl[3].card_suit && \
		pl[3].card_suit == pl[4].card_suit)
	{
		if (pl[0].number == 10 && \
			pl[1].number - pl[0].number == 1 && \
			pl[2].number - pl[1].number == 1 && \
			pl[3].number - pl[2].number == 1 && \
			pl[4].number - pl[3].number == 1)
		{
			return 110;
		}

		if (pl[1].number - pl[0].number == 1 && \
			pl[2].number - pl[1].number == 1 && \
			pl[3].number - pl[2].number == 1 && \
			pl[4].number - pl[3].number == 1)
		{
			return 100;
		}
		return 70;
	}
	if ((pl[1].number == pl[2].number && \
		pl[1].number == pl[3].number && \
		pl[1].number == pl[4].number) \
			|| 
		(pl[0].number == pl[1].number && \
		pl[0].number == pl[2].number && \
		pl[0].number == pl[3].number))
	{
		return 90;
	}
	if ((pl[2].number == pl[3].number && \
		pl[2].number == pl[4].number)
		||
		(pl[0].number == pl[1].number && \
		pl[0].number == pl[2].number))
	{
		if (pl[0].number != pl[1].number || pl[3].number != pl[4].number)
		{
			return 50;
		}
		else return 80;
	}
	if (pl[0].number == 14 && (pl[2].number - pl[1].number==1 && \
		pl[3].number - pl[2].number==1 && pl[4].number - pl[3].number == 1) ||
		pl[4].number == 14 && (pl[1].number - pl[0].number == 1 && \
			pl[2].number - pl[1].number == 1 && pl[3].number - pl[2].number == 1) ||
		(pl[1].number - pl[0].number == 1 && pl[2].number - pl[1].number == 1 && \
			pl[3].number - pl[2].number == 1 && pl[4].number - pl[3].number == 1))
	{
		return 60;
	}

	if ((pl[0].number == pl[1].number && pl[2].number == pl[3].number) ||
		(pl[1].number == pl[2].number && pl[3].number == pl[4].number) ||
		(pl[0].number == pl[1].number && pl[3].number == pl[4].number))
	{
		return 40;
	}

	if (pl[0].number == pl[1].number || pl[1].number == pl[2].number ||
		pl[2].number == pl[3].number || pl[3].number == pl[4].number)
	{
		return 30;
	}

	return pl[0].number;
}

// раздаем карты
void Poker::game()
{
	for (int8_t i = 0; i < 5; ++i)
	{
		player1[i] = this->my_deck[count_cards - 1];
		--(this->count_cards);
	}
	for (int8_t i = 0; i < 5; ++i)
	{
		player2[i] = this->my_deck[count_cards - 1];
		--(this->count_cards);
	}

	// сортируем карты первого игрока
	for (int8_t i = 0; i < 5; ++i)
	{
		for (int8_t j = 4; j > i; --j)
		{
			if (player1[j].number > player1[j - 1].number)
			{
				std::swap(player1[j], player1[j - 1]);
			}
		}
	}

	// сортируем карты второго игрока
	for (int8_t i = 0; i < 5; ++i)
	{
		for (int8_t j = 4; j > i; --j)
		{
			if (player2[j].number > player2[j - 1].number)
			{
				std::swap(player2[j], player2[j - 1]);
			}
		}
	}
}

// производим обмен
void Poker::exchange(short* v)
{
	for (int i{ 0 }; i < 5; ++i)
	{
		if (v[i] != -1)
		{
			player2[i] = this->my_deck[this->count_cards - 1];
			--(this->count_cards);
		}
	}
}