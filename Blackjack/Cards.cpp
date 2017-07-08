#include "stdafx.h"
#include <iostream>
#include "blackjack.h"
#include <random>

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
void shuffleDeck(Card deck[], int size) {
	for (int i = 0; i < size; ++i) {
		swapCard(deck[i], deck[getRandom(0, size - 1)]);
	}
}

// Returns an ordered deck. The bool is used to return a shuffled deck.
Card* getDeck(int amount, bool shuffled) {
	Card *deck = new Card[amount * 52];
	for (int i = 0; i < amount; ++i) {
		for (int suit = 0; suit < static_cast<int>(Card::Suit::MAX_SUITS); ++suit) {
			for (int rank = 0; rank < static_cast<int>(Card::Rank::MAX_RANKS); ++rank) {
				deck[i * 52 + suit * static_cast<int>(Card::Rank::MAX_RANKS) + rank] = Card(static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit));
			}
		}
	}
	if (shuffled) {
		shuffleDeck(deck, amount * 52);
	}
	return deck;
}

// Print the entire deck
void printDeck(Card deck[], int size) {
	for (int i = 0; i < size; ++i) {
        deck[i].printCard();
	}
	std::cout << '\n';
}

