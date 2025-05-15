#include "Deck.hpp"

#include <iostream>
#include <random>

Deck::Deck(std::vector<Card> cards) : cards(cards) {}

Deck::~Deck() {}

Card Deck::drawCard() {
	
	while (true) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dist(0, 51);

		if (cards.at(dist(gen)).isDrawn() == false) {
			Card drawnCard = cards.at(dist(gen));
			drawnCard.setDrawn(true);
			return drawnCard;
		}
		
	}
}

void Deck::shuffle()
{
	for (Card& card : cards) {
		card.setDrawn(false);
	}
}

