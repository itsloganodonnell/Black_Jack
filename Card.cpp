#include "Card.hpp"

Card::Card(std::string suit, std::string rank) : suit(suit), rank(rank), value(0), drawn(false)

{
	if (rank == "Ace") {
		value = 11;
	}
	else if (rank == "Jack" || rank == "Queen" || rank == "King") {
		value = 10;
	}
	else {
		value = std::stoi(rank);
	}
}

Card::~Card() {}

std::string Card::getSuit() const
{
	return suit;
}


void Card::setValue(int value)
{
	this->value = value;
}

std::string Card::getRank() const
{
	return rank;
}

int Card::getValue()
{
	return 0;
}

bool Card::isFaceCard() const
{
	return (rank == "Jack" || rank == "Queen" || rank == "King");
}

bool Card::isDrawn() const
{
	return drawn;
}

void Card::setDrawn(bool drawn)
{
	this->drawn = drawn;
}