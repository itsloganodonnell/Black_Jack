#include "Player.hpp"
#include "Card.hpp"

Player::Player(std::vector<Card> deck){}


void Player::addCard(Card card)
{
	playerHand.push_back(card);
}

int Player::getHandValue() const
{
	int i = 0;
	for (const Card& card : playerHand) {
		i += card.getValue();
	}
	return i;
}

int Player::getChips() const
{
	return this -> chips;
}
