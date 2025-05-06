#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <string>

class Card()
{
public:
	Card(char suit, std::string rank);
	char getSuit() const;
	int getValue() const;
	std::string getRank() const;
	std::string displayCard() const;
	bool isFaceCard() const;
	bool isDrawn() const;

private:
	char suit;
	int value;
	std::string rank;
	bool isDrawn;
}

#endif