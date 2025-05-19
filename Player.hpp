#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "Card.hpp"
#include "Deck.hpp"
#include <iostream>

class Player {
public:
    Player() = default;
    Player(std::vector<Card> deck); 
    ~Player();

    void addCard(Card card);
    int getHandValue() const;
    int getChips() const;
    Card getCard(int i);
    int getHandSize();
    void clearHand();

    void resetChips() {
        chips = 1000;
    }

    bool hasBlackJack(Player player);

    void placeBet() {
        int amount = 0;
        std::cout << "Enter bet amount (Must be between 5 & " << chips << "): ";
        std::cin >> amount;
        if (amount < 5 || amount > chips) {
            std::cout << "Invalid bet amount. Please enter a value between 5 and " << chips << ".\n";
            placeBet(); 
        }
        else {
            bet = amount;
        }
    }

    void hit(Deck& deck);
    void doubleDown(Card card);

	void blackJackBet() {
		chips += bet + (bet/2);
		std::cout << "Your new chip total is: " << chips << std::endl;
		bet = 0;
	}

    void winBet() {
        chips += bet;
        std::cout << "Your new chip total is: " << chips << std::endl;
        bet = 0;
    }

    void loseBet() {
        chips -= bet;
        std::cout << "You lose! Your new chip total is: " << chips << std::endl;
        bet = 0;
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