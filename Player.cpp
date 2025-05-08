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

void Player::hit(Dealer gameDealer)
{
	playerHand.addCard(gameDealer.dealCard());
	std::cout << "You hit and received a card." << std::endl;

}


void Player::doubleDown(Dealer gameDealer)
{
	playerHand.addCard(gameDealer.dealCard());
	bet *= 2;
	std::cout << "You doubled down. Your bet is now " << bet << std::endl;
}

Player::~Player() {
	
}