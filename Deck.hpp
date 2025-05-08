#ifndef DECK_HPP
#define DECK_HPP

#include "Card.hpp"
#include <string>
#include <vector>

class Deck
{
public:
	Deck(std::vector<Card> cards);
	~Deck();

	void shuffle();
	Card drawCard();

protected:
	std::vector<Card> cards;
};

#endif