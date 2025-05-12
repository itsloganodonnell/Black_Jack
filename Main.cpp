#include "Card.hpp"
#include "Deck.hpp"
#include "Player.hpp"
#include "Dealer.hpp"
#include <iostream>
#include <vector>


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

Deck gameDeckObj(gameDeck);

void playGame(bool freshGame, Player& player1, Dealer& dealer) {
    if (freshGame) {
        std::cout << "Welcome to Blackjack!" << std::endl;
        player1.resetChips();
    }
    else {
        std::cout << "Welcome back to Blackjack!" << std::endl;
    }

    std::cout << "Player's chips: " << player1.getChips() << std::endl;
    player1.placeBet();

    player1.addCard(gameDeckObj.drawCard());
    player1.addCard(gameDeckObj.drawCard());
    dealer.addCard(gameDeckObj.drawCard());
    dealer.addCard(gameDeckObj.drawCard());

    std::cout << "Player's hand value: " << player1.getHandValue() << std::endl;
    std::cout << "Dealer's visible card: "
        << dealer.getCard(0).getRank() << " of " << dealer.getCard(0).getSuit() << std::endl;
    std::cout << "Dealer has a card that is still hidden from you." << std::endl;

    std::string choice;
    bool playerTurnOver = false;
    while (!playerTurnOver && player1.getHandValue() <= 21) {
        std::cout << "Would you like to 'hit', 'stand', or 'double down'? ";
        std::cin >> choice;

        if (choice == "hit") {
            player1.addCard(gameDeckObj.drawCard());
            std::cout << "Player's hand value: " << player1.getHandValue() << std::endl;
            if (player1.getHandValue() > 21) {
                std::cout << "Player busts!\n";
                player1.loseBet();
                return;
            }
        }
        else if (choice == "double down") {
            player1.doubleDown(gameDeckObj.drawCard());
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

    std::cout << "Dealer's turn...\n";
    while (dealer.getHandValue() < 17) {
        dealer.addCard(gameDeckObj.drawCard());
        std::cout << "Dealer hits. New value: " << dealer.getHandValue() << std::endl;
    }

    int playerTotal = player1.getHandValue();
    int dealerTotal = dealer.getHandValue();

    if (dealerTotal > 21) {
        std::cout << "Dealer busts! Player wins.\n";
        player1.winBet();
    }
    else if (playerTotal > dealerTotal) {
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


void playAnotherGame(Player& player1, Dealer& dealer) {
    std::string choice;
    std::cout << "Would you like to play another game? (yes/no): ";
    std::cin >> choice;
    if (choice == "yes") {
        playGame(false, player1, dealer);
        playAnotherGame(player1, dealer);
    }
    else if (choice == "no") {
        std::cout << "Thank you for playing!" << std::endl;
    }
    else {
        std::cout << "Invalid choice. Please enter 'yes' or 'no'." << std::endl;
        playAnotherGame(player1, dealer);
    }
}

void playBlackjack() {
    Player player1;
    Dealer dealer;
    playGame(true, player1, dealer);
    playAnotherGame(player1, dealer);
}

int main() {
    playBlackjack();
}