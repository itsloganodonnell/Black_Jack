#ifndef DEALER_HPP
#define DEALER_HPP

#include <vector>
#include "Card.hpp"
#include "Deck.hpp"

class Dealer {
public:
	Dealer(std::vector<Card> deck);
	void addCard(Card card);
	int getHandValue() const;
	Card getCard(int index) const;


private:
	std::vector<Card> dealerHand;
};

#endif