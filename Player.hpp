#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <vector>
#include "Card.hpp"
#include "Deck.hpp"

class Player {
public:
	Player(std::vector<Card> deck);
	void addCard(Card card);
	int getHandValue() const;
	int getChips() const;
	void resetChips() {
		chips = 1000;
	}
private:
	std::vector<Card> playerHand;
	int chips = 1000;
};

#endif