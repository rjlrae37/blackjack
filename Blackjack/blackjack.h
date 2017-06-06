#pragma once
#include <array>

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
void shuffleDeck(std::array<Card, 52> &deck);
std::array<Card, 52> getDeck(bool shuffled = false);
void printDeck(const std::array<Card, 52> &deck);
int getCardValue(const Card &card, const bool &aceEleven = true);

#endif // !CARDS
