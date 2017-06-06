// Blackjack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "blackjack.h"
#include <iostream>
#include <array>
#include <string>

// Get player input
char getPlayerChoice()
{
	std::cout << "Use (h) to hit, or (s) to stand: ";
	char choice;
	do {
		std::cin >> choice;
	} while (choice != 'h' && choice != 's');

	return choice;
}

// Deal a card, update scores, inform the player about it
void dealCard(int &score, const Card *&cardPtr, int &aces, bool player) {
	score += getCardValue(*cardPtr++);
	if ((*(cardPtr - 1)).rank == Rank::ACE) {
		++aces;
	}

	std::string name, verb;
	if (player) {
		name = "You";
		verb = "have";
	}
	else {
		name = "The dealer";
		verb = "has";
	}
	std::cout << name << " got ";
	printCard(*(cardPtr - 1));
	std::cout << "and " << verb << " a score of " << score << ".\n";
}

// Game logic
bool playBlackjack(const std::array<Card, 52> &deck) {
	// Setup
	const Card *cardPtr = &deck[0];
	int dealerScore = 0;
	int playerScore = 0;
	int dealerAces = 0;
	int playerAces = 0;

	// Deal first cards
	dealCard(dealerScore, cardPtr, dealerAces, false);
	dealCard(dealerScore, cardPtr, dealerAces, false);

	dealCard(playerScore, cardPtr, playerAces, true);
	dealCard(playerScore, cardPtr, playerAces, true);

	// Player turn
	while (true) {
		if (playerScore > 21) {
			if (playerAces) {
				playerScore -= 10;
				--playerAces;
				std::cout << "Your ace is now counted as 1. You now have a score of " << playerScore << ".\n";
			}
			else {
				return false;
			}
		}

		if (getPlayerChoice() == 'h') {
			dealCard(playerScore, cardPtr, playerAces, true);
		}
		else {
			break;
		}
	}

	// Dealer turn
	while (true) {
		if (dealerScore > 21) {
			if (dealerAces) {
				playerScore -= 10;
				--dealerAces;
				std::cout << "The dealer his ace is now counted as 1. His score is now " << dealerScore << ".\n";
			}
			else {
				return true;
			}
		}

		if (dealerScore < 17) {
			dealCard(dealerScore, cardPtr, dealerAces, false);
		}
		else {
			break;
		}
	}

	return (playerScore > dealerScore);
}

int main()
{
	do {
		bool playerWin = playBlackjack(getDeck(true));

		if (playerWin) {
			std::cout << "Congratulations! You win!!!" << '\n';
		}
		else {
			std::cout << "Sadly, you lost." << '\n';
		}

		std::cout << "Do you want to play another game? (y/n) ";
		char choice;
		do {
			std::cin >> choice;
		} while (choice != 'y' && choice != 'n');

		if (choice == 'n') {
			break;
		}
	} while (true);
    return 0;
}

