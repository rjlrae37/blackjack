#include "stdafx.h"
#include <iostream>
#include <random>
#include <vector>
#include "blackjack.h"

Deck::Deck()
{
    Deck(1, true);
}

Deck::Deck(int amount, bool shuffled)
{
    cards.resize(amount * 52);
    for (int i = 0; i < amount; ++i) {
        for (int suit = 0; suit < static_cast<int>(Card::Suit::MAX_SUITS); ++suit) {
            for (int rank = 0; rank < static_cast<int>(Card::Rank::MAX_RANKS); ++rank) {
                cards[i * 52 + suit * static_cast<int>(Card::Rank::MAX_RANKS) + rank] = Card(static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit));
            }
        }
    }
    if (shuffled) {
        shuffleDeck(amount * 52);
    }
}

// Swap two cards
void Deck::swapCard(Card &first, Card &second) {
    Card swap = first;
    first = second;
    second = swap;
}

// Get a random number between two integers using a Mersenne Twister
int Deck::getRandom(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 mersenne(rd());
    std::uniform_int_distribution<int> dis(min, max);
    return dis(mersenne);
}

// Shuffle a deck of cards random
void Deck::shuffleDeck(int size) {
    for (int i = 0; i < size; ++i) {
        swapCard(cards[i], cards[getRandom(0, size - 1)]);
    }
}

// Print the entire deck
void Deck::printDeck(int size) {
    for (int i = 0; i < size; ++i) {
        cards[i].printCard();
    }
    std::cout << '\n';
}
