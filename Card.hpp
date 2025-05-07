#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <string>

class Card
{
public:
	Card(char suit, std::string rank);
	char getSuit() const;
	int getValue() const;
	void setValue(int value);
	std::string getRank() const;
	bool isFaceCard() const;
	bool isDrawn() const;
	void setDrawn(bool drawn);

private:
	char suit;
	int value;
	std::string rank;
	bool drawn;
};

#endif