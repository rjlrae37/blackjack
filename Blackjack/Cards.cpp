#include "stdafx.h"
#include <iostream>
#include "blackjack.h"
#include <array>
#include <random>

// Prints the value of a card.
// The bool determines whether the programs prints a newline or a space between cards.
void printCard(const Card card, bool newline) {
	switch (card.rank)
	{
		case Rank::TWO: 	std::cout << "two";		break;
		case Rank::THREE:	std::cout << "three";	break;
		case Rank::FOUR:	std::cout << "four";	break;
		case Rank::FIVE:	std::cout << "five";	break;
		case Rank::SIX:		std::cout << "six";		break;
		case Rank::SEVEN:	std::cout << "seven";	break;
		case Rank::EIGHT:	std::cout << "eight";	break;
		case Rank::NINE:	std::cout << "nine";	break;
		case Rank::TEN:		std::cout << "ten";		break;
		case Rank::JACK:	std::cout << "jack";	break;
		case Rank::QUEEN:	std::cout << "queen";	break;
		case Rank::KING:	std::cout << "king";	break;
		case Rank::ACE:		std::cout << "ace";		break;
		default:									break;
	}
	switch (card.suit)
	{
		case Suit::CLUB:	std::cout << " of clubs";		break;
		case Suit::DIAMOND: std::cout << " of diamonds";	break;
		case Suit::HEART:	std::cout << " of hearts";		break;
		case Suit::SPADE:	std::cout << " of spades";		break;
		default:											break;
	}
	if (newline) {
		std::cout << '\n';
	}
	else {
		std::cout << ' ';
	}
}

// Swap two cards
void swapCard(Card &first, Card &second) {
	Card swap = first;
	first = second;
	second = swap;
}

// Get a random number between two integers using a Mersenne Twister
int getRandom(int min, int max)
{
	static std::random_device rd;
	static std::mt19937 mersenne(rd());
	std::uniform_int_distribution<int> dis(min, max);
	return dis(mersenne);
}

// Shuffle a deck of cards random
void shuffleDeck(std::array<Card, 52> &deck) {
	for (Card &card : deck) {
		swapCard(card, deck[getRandom(0, 51)]);
	}
}

// Returns an ordered deck. The bool is used to return a shuffled deck.
std::array<Card, 52> getDeck(bool shuffled) {
	std::array<Card, 52> deck;
	for (int suit = 0; suit < static_cast<int>(Suit::MAX_SUITS); ++suit) {
		for (int rank = 0; rank < static_cast<int>(Rank::MAX_RANKS); ++rank) {
			deck[suit * static_cast<int>(Rank::MAX_RANKS) + rank] = { static_cast<Rank>(rank), static_cast<Suit>(suit) };
		}
	}
	if (shuffled) {
		shuffleDeck(deck);
	}
	return deck;
}

// Print the entire deck
void printDeck(const std::array<Card, 52> &deck) {
	for (const Card &card : deck) {
		printCard(card);
	}
	std::cout << '\n';
}

// Get the value of a card. The value of the ace can be controlled using a boolean
int getCardValue(const Card &card, const bool &aceEleven) {
	switch (card.rank)
	{
		case Rank::TWO:
		case Rank::THREE:
		case Rank::FOUR:
		case Rank::FIVE:
		case Rank::SIX:
		case Rank::SEVEN:
		case Rank::EIGHT:
		case Rank::NINE:
		case Rank::TEN:		return static_cast<int>(card.rank) + 2;	break;
		case Rank::JACK:	
		case Rank::QUEEN:	
		case Rank::KING:	return 10;	break;
		case Rank::ACE:		return aceEleven ? 11 : 1;	break;
	}
}
