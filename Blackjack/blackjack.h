#pragma once

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

void swapCard(Card &first, Card &second);
void shuffleDeck(Card deck[], int size);
Card* getDeck(int amount = 1, bool shuffled = true);
void printDeck(const Card deck[], int size);

#endif // !CARDS
