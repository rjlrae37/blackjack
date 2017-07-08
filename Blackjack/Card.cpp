#include "stdafx.h"
#include <iostream>
#include "blackjack.h"

Card::Card(Rank r, Suit s) : rank(r), suit(s) {}

// Prints the value of a card.
// The bool determines whether the programs prints a newline or a space between cards.
void Card::printCard(bool newline) {
    switch (rank)
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
    switch (suit)
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

// Get the value of a card. The value of the ace can be controlled using a boolean
int Card::getCardValue(const bool &aceEleven) {
    switch (rank)
    {
        case Card::Rank::TWO:
        case Card::Rank::THREE:
        case Card::Rank::FOUR:
        case Card::Rank::FIVE:
        case Card::Rank::SIX:
        case Card::Rank::SEVEN:
        case Card::Rank::EIGHT:
        case Card::Rank::NINE:
        case Card::Rank::TEN:		return static_cast<int>(rank) + 2;	break;
        case Card::Rank::JACK:
        case Card::Rank::QUEEN:
        case Card::Rank::KING:	    return 10;	break;
        case Card::Rank::ACE:		return aceEleven ? 11 : 1;	break;
    }
}

// Return the rank of the card
Card::Rank Card::getRank() const
{
    return rank;
}

// Return the suit of the card
Card::Suit Card::getSuit() const
{
    return suit;
}