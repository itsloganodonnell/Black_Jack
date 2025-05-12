#ifndef CARD_HPP
#define CARD_HPP

#include <string>

class Card
{
public:
	Card(std::string suit, std::string rank);

	~Card();

	std::string getSuit() const;
	std::string getRank() const;
	int getValue() const;
	bool isFaceCard() const;
	bool isDrawn() const;

	void setValue(int value);
	void setDrawn(bool drawn);

private:
	std::string suit;
	std::string rank;
	int value;
	bool drawn;
};

#endif