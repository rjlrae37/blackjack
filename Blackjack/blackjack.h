#pragma once

#ifndef CARDS
#define CARDS

enum class Rank {
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE,
	MAX_RANKS
};

enum class Suit {
	CLUB,
	DIAMOND,
	HEART,
	SPADE,
	MAX_SUITS
};

struct Card {
	Rank rank;
	Suit suit;
};

void printCard(const Card card, bool newline = false);
void swapCard(Card &first, Card &second);
void shuffleDeck(Card deck[], int size);
Card* getDeck(int amount = 1, bool shuffled = false);
void printDeck(const Card deck[], int size);
int getCardValue(const Card &card, const bool &aceEleven = true);

#endif // !CARDS
