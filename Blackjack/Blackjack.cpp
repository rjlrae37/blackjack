// Blackjack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "blackjack.h"
#include <iostream>
#include <string>
#include <vector>

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
void dealCard(int &score, Card *&cardPtr, int &aces, bool player) {
	score += (*(cardPtr++)).getCardValue();
	if ((*(cardPtr - 1)).getRank() == Card::Rank::ACE) {
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
    (*(cardPtr - 1)).printCard();
	std::cout << "and " << verb << " a score of " << score << ".\n";
}

// Game logic
bool playBlackjack(Deck deck) {
	// Setup
	Card *cardPtr = &deck.cards[0];
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
				dealerScore -= 10;
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
	std::cout << "Welcome to blackjack!\n";

	do {
		std::cout << "Hit (p) to play, (e) to exit or (h) to get help. ";
		char command;
		do {
			std::cin >> command;
		} while (command != 'p' && command != 'h' && command != 'e' && command != 'i');

		switch (command)
		{
			case 'p':
			{
				std::cout << "How many decks do you want to use? (1-6) ";
				int deckCount;
				std::cin >> deckCount;
				if (deckCount > 6) deckCount = 6;
				if (deckCount < 1) deckCount = 1;
				do {
                    bool playerWin = playBlackjack(Deck(deckCount));

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
				break;
			}
			case 'h':
				std::cout << "In blackjack your goal is to obtain a score as high as possible. "
					"You gain points by drawing a card. The rank of the card is added to your total score. "
					"The ace is valued at 11 points, unless your score is higher than 21, "
					"than it is valued at 1 point. When you have more than 21 points, you lose. "
					"The highest score wins.\nControls:\nIn game:\n(h) -- hit, get another card.\n(s) -- stand, end turn."
					"\nIn the menu:\n(p) -- play the game.\n(h) -- help.\n(i) -- info and license.\n(e) -- exit.\n";
				break;
			case 'i':
				std::cout << "The project was inspired by http://www.learncpp.com/. "
					"The source code can be found at https://github.com/wzwietering/blackjack.\n\n"
					"(c) Wilmer Zwietering 2017\n\nPermission is hereby granted, free of charge, to any person obtaining a copy "
					"of this software and associated documentation files(the \"Software\"), to deal "
					"in the Software without restriction, including without limitation the rights "
					"to use, copy, modify, merge, publish, distribute, sublicense, and/or sell "
					"copies of the Software, and to permit persons to whom the Software is "
					"furnished to do so, subject to the following conditions : \n\n"

					"The above copyright notice and this permission notice shall be included in all "
					"copies or substantial portions of the Software. \n\n"

					"THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR "
					"IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, "
					"FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE "
					"AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER "
					"LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, "
					"OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE "
					"SOFTWARE.\n";
				break;
			case 'e':
				return 0;
		}		
	} while (true);
	return 0;
}

