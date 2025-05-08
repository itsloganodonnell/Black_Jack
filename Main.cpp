#include "Card.hpp"
#include "Deck.hpp"
#include "Player.hpp"
#include "Dealer.hpp"
#include <iostream>
#include <vector>

// suit rank
std::vector<Card> gameDeck = {
	Card("Hearts", "2"),
	Card("Spades", "2"),
	Card("Diamonds", "2"),
	Card("Clubs", "2"),
	Card("Hearts", "3"),
	Card("Spades", "3"),
	Card("Diamonds", "3"),
	Card("Clubs", "3"),
	Card("Hearts", "4"),
	Card("Spades", "4"),
	Card("Diamonds", "4"),
	Card("Clubs", "4"),
	Card("Hearts", "5"),
	Card("Spades", "5"),
	Card("Diamonds", "5"),
	Card("Clubs", "5"),
	Card("Hearts", "6"),
	Card("Spades", "6"),
	Card("Diamonds", "6"),
	Card("Clubs", "6"),
	Card("Hearts", "7"),
	Card("Spades", "7"),
	Card("Diamonds", "7"),
	Card("Clubs", "7"),
	Card("Hearts", "8"),
	Card("Spades", "8"),
	Card("Diamonds", "8"),
	Card("Clubs", "8"),
	Card("Hearts", "9"),
	Card("Spades", "9"),
	Card("Diamonds", "9"),
	Card("Clubs", "9"),
	Card("Hearts", "10"),
	Card("Spades", "10"),
	Card("Diamonds", "10"),
	Card("Clubs", "10"),
	Card("Hearts", "Jack"),
	Card("Spades", "Jack"),
	Card("Diamonds", "Jack"),
	Card("Clubs", "Jack"),
	Card("Hearts", "Queen"),
	Card("Spades", "Queen"),
	Card("Diamonds", "Queen"),
	Card("Clubs", "Queen"),
	Card("Hearts", "King"),
	Card("Spades", "King"),
	Card("Diamonds", "King"),
	Card("Clubs", "King"),
	Card("Hearts", "Ace"),
	Card("Spades", "Ace"),
	Card("Diamonds", "Ace"),
	Card("Clubs", "Ace"),
};

void playGame(bool freshGame) {
	
	if (freshGame) {
		std::cout << "Welcome to Blackjack!" << std::endl;
		Player player1(gameDeck);
		Dealer dealer(gameDeck);
		player1.resetChips();
	}
	else {
		std::cout << "Welcome back to Blackjack!" << std::endl;
	}
	
	std::cout << "Player's chips: " << player1.getChips() << std::endl;
	player1.placeBet();
	
	player1.addCard(dealer.dealCard());
	player1.addCard(dealer.dealCard());
	dealer.addCard(dealer.dealCard());
	dealer.addCard(dealer.dealCard());
	
	std::cout << "Player's hand value: " << player1.getHandValue() << std::endl;
	std::cout << "Dealer's visible card: "
		<< dealer.getCard(0).getRank() << " of " << dealer.getCard(0).getSuit() << std::endl;
	std::cout << "Dealer has a card that is still hidden from you " << std::endl;

	std::cout << "Would you like to 'hit' or 'stand' or 'double down'?" << std::endl;
	std::string choice;
	std::cin >> choice;

	std::string choice;
	bool playerTurnOver = false;
	while (!playerTurnOver && player1.getHandValue() <= 21) {
		std::cout << "Would you like to 'hit', 'stand', or 'double down'? ";
		std::cin >> choice;

		if (choice == "hit") {
			player1.hit(dealer);
			std::cout << "Player's hand value: " << player1.getHandValue() << std::endl;
			if (player1.getHandValue() > 21) {
				std::cout << "Player busts!\n";
				player1.loseBet();
				return;
			}
		}
		else if (choice == "double down") {
			player1.doubleDown(dealer);
			std::cout << "Player's hand value: " << player1.getHandValue() << std::endl;
			playerTurnOver = true; 
		}
		else if (choice == "stand") {
			playerTurnOver = true;
		}
		else {
			std::cout << "Invalid choice. Please try again.\n";
		}
	}
	std::cout << "Dealer's total hand value is...\n";
	dealer.getHandValue();  

	while (dealer.getHandValue() < 17) {
		dealer.hit(gameDeck);
		std::cout << "Dealer hits. New value: " << dealer.getHandValue() << std::endl;
	}

	if (dealer.getHandValue() > 21) {
		std::cout << "Dealer busts! Player wins.\n";
		player1.winBet();
		return;
	}

	
	int playerTotal = player1.getHandValue();
	int dealerTotal = dealer.getHandValue();

	if (playerTotal > dealerTotal) {
		std::cout << "Player wins! (" << playerTotal << " vs " << dealerTotal << ")\n";
		player1.winBet();
	}
	else if (playerTotal < dealerTotal) {
		std::cout << "Dealer wins. (" << dealerTotal << " vs " << playerTotal << ")\n";
		player1.loseBet();
	}
	else {
		std::cout << "Push (tie). Player gets bet back.\n";
		player1.pushBet();
	}

	std::cout << "Player's chips: " << player1.getChips() << std::endl;
}


void playAnotherGame() {
	std::string choice;
	std::cout << "Would you like to play another game? (yes/no): ";
	std::cin >> choice;
	if (choice == "yes") {
		playGame(false);
	}
	else if (choice == "no") {
		std::cout << "Thank you for playing!" << std::endl;
	}
	else {
		std::cout << "Invalid choice. Please enter 'yes' or 'no'." << std::endl;
		playAnotherGame();
	}
}
void playBlackjack() {
	playGame(true);
	playAnotherGame();
}
int main() {
	playBlackjack();
}