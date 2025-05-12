#include "Player.hpp"
#include "Card.hpp"

Player::Player(std::vector<Card> deck){}


void Player::addCard(Card card)
{
	playerHand.push_back(card);
}

int Player::getHandValue() const
{
    int totalValue = 0;
    int aceCount = 0;

    
    for (const Card& card : playerHand) {
        int value = card.getValue();
        totalValue += value;

        if (card.getRank() == "Ace") {
            aceCount++;
        }
    }

    while (totalValue > 21 && aceCount > 0) {
        totalValue -= 10;
        aceCount--;
    }
    return totalValue;
}

int Player::getChips() const
{
	return this -> chips;
}

void Player::hit(Deck& deck)
{
	addCard(deck.drawCard());
	std::cout << "You hit and received a card." << std::endl;

}


void Player::doubleDown(Card card) {
	// Double the bet
	bet *= 2;

	// Add the card to the player's hand
	addCard(card);

	// Print the updated hand value
	std::cout << "Player doubles down! New hand value: " << getHandValue() << std::endl;
}

Player::~Player() {
	
}