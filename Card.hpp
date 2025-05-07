#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>
#include <string>

class Card
{
public:
	Card(std::string suit, std::string rank);
	std::string getSuit() const;
	int getValue() const;
	void setValue(int value);
	std::string getRank() const;
	bool isFaceCard() const;
	bool isDrawn() const;
	void setDrawn(bool drawn);

private:
	std::string suit;
	int value;
	std::string rank;
	bool drawn;
};

#endif