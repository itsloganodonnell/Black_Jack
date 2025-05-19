#include "Card.hpp"
#include "Deck.hpp"
#include "Player.hpp"
#include "Dealer.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>

std::vector<Card> gameDeck = {
    Card("Hearts", "2"), Card("Spades", "2"), Card("Diamonds", "2"), Card("Clubs", "2"),
    Card("Hearts", "3"), Card("Spades", "3"), Card("Diamonds", "3"), Card("Clubs", "3"),
    Card("Hearts", "4"), Card("Spades", "4"), Card("Diamonds", "4"), Card("Clubs", "4"),
    Card("Hearts", "5"), Card("Spades", "5"), Card("Diamonds", "5"), Card("Clubs", "5"),
    Card("Hearts", "6"), Card("Spades", "6"), Card("Diamonds", "6"), Card("Clubs", "6"),
    Card("Hearts", "7"), Card("Spades", "7"), Card("Diamonds", "7"), Card("Clubs", "7"),
    Card("Hearts", "8"), Card("Spades", "8"), Card("Diamonds", "8"), Card("Clubs", "8"),
    Card("Hearts", "9"), Card("Spades", "9"), Card("Diamonds", "9"), Card("Clubs", "9"),
    Card("Hearts", "10"), Card("Spades", "10"), Card("Diamonds", "10"), Card("Clubs", "10"),
    Card("Hearts", "Jack"), Card("Spades", "Jack"), Card("Diamonds", "Jack"), Card("Clubs", "Jack"),
    Card("Hearts", "Queen"), Card("Spades", "Queen"), Card("Diamonds", "Queen"), Card("Clubs", "Queen"),
    Card("Hearts", "King"), Card("Spades", "King"), Card("Diamonds", "King"), Card("Clubs", "King"),
    Card("Hearts", "Ace"), Card("Spades", "Ace"), Card("Diamonds", "Ace"), Card("Clubs", "Ace"),
};

Deck gameDeckObj(gameDeck);

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

bool blackJackCheck(Player& player, Dealer& dealer) {
    if (player.hasBlackJack(player)) {
        std::cout << "Player has a Blackjack! Player wins!\n";
        player.blackJackBet();
        return true;
    }
    else if (dealer.hasBlackJack(dealer)) {
        std::cout << "Dealer has a Blackjack! Dealer wins!\n";
        player.loseBet();
        return true;
    }
    else if (player.getHandValue() == 21 && dealer.getHandValue() == 21) {
        std::cout << "Both player and dealer have a Blackjack! It's a push!\n";
        player.pushBet();
        return true;
    }
    return false;
}

void bustCheck(Player& player, Dealer& dealer) {
    if (player.getHandValue() > 21) {
        std::cout << "Player busts! Dealer wins.\n";
        player.loseBet();
    }
    else if (dealer.getHandValue() > 21) {
        std::cout << "Dealer busts! Player wins.\n";
        player.winBet();
    }
}

void winCheck(Player& player, Dealer& dealer) {
    if (dealer.getHandValue() > 21) {
        std::cout << "Dealer busts! Player wins.\n";
        player.winBet();
    }
    else if (player.getHandValue() == 21 && dealer.getHandValue() == 21) {
        std::cout << "Both player and dealer have a Blackjack! It's a push!\n";
        player.pushBet();
    }
    else if (player.getHandValue() > dealer.getHandValue() && player.getHandValue() <= 21) {
        std::cout << "Player wins! (" << player.getHandValue() << " vs " << dealer.getHandValue() << ")\n";
        player.winBet();
    }
    else if (player.getHandValue() < dealer.getHandValue()) {
        std::cout << "Dealer wins. (" << dealer.getHandValue() << " vs " << player.getHandValue() << ")\n";
        player.loseBet();
    }
    else {
        std::cout << "Push (tie). Player gets bet back.\n";
        player.pushBet();
    }
}

void playGame(bool freshGame, Player& player1, Dealer& dealer) {
    player1.clearHand();
    dealer.clearHand();
// Move counter outside the function to persist across rounds
static int counter = 0;

if (freshGame) {
    std::cout << "Welcome to Blackjack!" << std::endl;
    player1.resetChips();
    gameDeckObj.shuffle();
    counter = 0;
} else {
    std::cout << "Welcome back to Blackjack!" << std::endl;
}

counter++;

if (counter == 5) {
    gameDeckObj.shuffle();
    counter = 0;
}

    std::cout << "Player's chips: " << player1.getChips() << std::endl;
    player1.placeBet();

    player1.addCard(gameDeckObj.drawCard());
    player1.addCard(gameDeckObj.drawCard());
    dealer.addCard(gameDeckObj.drawCard());
    dealer.addCard(gameDeckObj.drawCard());

    if (blackJackCheck(player1, dealer)) return;

    std::cout << "Player's hand: " << player1.getCard(0).getRank() << " of " << player1.getCard(0).getSuit()
        << " and " << player1.getCard(1).getRank() << " of " << player1.getCard(1).getSuit()
        << "\nValue: " << player1.getHandValue() << std::endl;

    std::cout << "Dealer's visible card: " << dealer.getCard(0).getRank()
        << " of " << dealer.getCard(0).getSuit() << std::endl;
    std::cout << "Dealer has a card that is still hidden from you." << std::endl;

    char choice;
    bool playerTurnOver = false;

    while (!playerTurnOver && player1.getHandValue() <= 21) {
        std::cout << "Would you like to [H]it, [S]tand, or [D]ouble down? ";
        std::cin >> choice;

        if (choice == 'H' || choice == 'h') {
            player1.addCard(gameDeckObj.drawCard());
            std::cout << "Player's new card: "
                << player1.getCard(player1.getHandSize() - 1).getRank() << " of "
                << player1.getCard(player1.getHandSize() - 1).getSuit()
                << "\nValue: " << player1.getHandValue() << std::endl;
            if (player1.getHandValue() > 21) {
                bustCheck(player1, dealer);
                return;
            }
        }
        else if (choice == 'D' || choice == 'd') {
            if (player1.getHandSize() == 2) {
                player1.doubleDown(gameDeckObj.drawCard());
                std::cout << "Player's hand value: " << player1.getHandValue() << std::endl;
                if (player1.getHandValue() > 21) {
                    bustCheck(player1, dealer);
                    return;
                }
            }
            else {
                std::cout << "You can only double down on your first two cards.\n";
                continue;
            }
            playerTurnOver = true;
        }
        else if (choice == 'S' || choice == 's') {
            playerTurnOver = true;
        }
        else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    std::cout << "Dealer's turn...\n";

    while (dealer.getHandValue() < 17) {
        dealer.addCard(gameDeckObj.drawCard());
        std::cout << "Dealer hits.\nDealer's new card: "
            << dealer.getCard(dealer.getHandSize() - 1).getRank() << " of "
            << dealer.getCard(dealer.getHandSize() - 1).getSuit()
            << "\nDealer's new hand value: " << dealer.getHandValue() << std::endl;
    }

    winCheck(player1, dealer);
    std::cout << "Player's chips: " << player1.getChips() << std::endl;
}

void playAnotherGame(Player& player1, Dealer& dealer) {
    char choice;
    std::cout << "Would you like to play another round? [Y]es or [N]o: ";
    std::cin >> choice;

    if (choice == 'Y' || choice == 'y') {
        clearScreen();
        playGame(false, player1, dealer);
        playAnotherGame(player1, dealer);
    }
    else if (choice == 'N' || choice == 'n') {
        bool go = true;
        while (go) {
			std::cout << "Are you sure? [Y]es or [N]o: ";
            std::cin >> choice;

            if (choice == 'N' || choice == 'n') {
                clearScreen();
				std::cout << "That's what I thought." << std::endl;
                playGame(false, player1, dealer);
                playAnotherGame(player1, dealer);
                go = false;
            }
        }
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
