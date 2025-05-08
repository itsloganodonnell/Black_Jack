#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <vector>
#include "Card.hpp"
#include "Deck.hpp"
#include "Dealer.hpp"
#include <iostream>

class Player {
public:
	Player(std::vector<Card> deck);
	~Player();

	void addCard(Card card);
	int getHandValue() const;
	int getChips() const;
	void resetChips() {
		chips = 1000;
	}
	void placeBet() {
		int amount = 0;
		std::cout << "Enter bet amount (Must be between 5 & " << chips << ": ";
		std::cin >> amount;
		if (amount < 5 || amount > chips) {
			std::cout << "Invalid bet amount. Please enter a value between 5 and " << chips << "." << std::endl;
			placeBet(); 
		}
		else {
			bet = amount;
		}
	}
	void hit();
	void doubleDown();
	void winBet() {
		chips += bet * 2;
		std::cout << "You win! Your new chip total is: " << chips << std::endl;
	}
	void loseBet() {
		chips -= bet;
		std::cout << "You lose! Your new chip total is: " << chips << std::endl;
	}
	void pushBet() {
		std::cout << "Push! Your bet is returned. Your chip total is: " << chips << std::endl;
		bet = 0;
	}
private:
	std::vector<Card> playerHand;
	int chips = 1000;
	int bet = 0;
};

#endif