#pragma once
#include <vector>

#ifndef CARDS
#define CARDS

class Card {
public:
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
private:
    Rank rank;
    Suit suit;
public:
    Card(Rank r = Rank::MAX_RANKS, Suit s = Suit::MAX_SUITS);
    void printCard(bool newline = false);
    int getCardValue(const bool &aceEleven = true);
    Rank getRank() const;
    Suit getSuit() const;
};

class Deck {
public:
    std::vector<Card> cards;
    Deck();
    Deck(int amount, bool shuffled = true);
    void swapCard(Card &first, Card &second);
    void shuffleDeck(int size);
    void printDeck(int size);
private:
    int getRandom(int min, int max);
};


#endif // !CARDS
