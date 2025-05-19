#include "Player.hpp"
#include "Card.hpp"

Player::Player(std::vector<Card> deck){}


void Player::addCard(Card card)
{
	playerHand.push_back(card);
}

Card Player::getCard(int i) {
	if (i >= 0 && i < static_cast<int>(playerHand.size())) {
		return playerHand[i];
	}
	throw std::out_of_range("Player hand index out of range");
}

int Player::getHandSize() {
	return playerHand.size();
}

bool Player::hasBlackJack(Player player) {
    if (player.getHandValue() == 21) {
        return true;
    }
    else {
        return false;
    }
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
	std::cout << "Player doubles down!" << std::endl;

    std::cout << "Player's new card: "
        << this->getCard(this->getHandSize() - 1).getRank() << " of "
        << this->getCard(this->getHandSize() - 1).getSuit() << std::endl;
}

void Player::clearHand() {
	playerHand.clear();
}

Player::~Player() {
}