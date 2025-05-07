#include "Card.hpp"

Card::Card(char suit, std::string rank) : suit(suit), rank(rank), drawn(false)
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

char Card::getSuit() const
{
	return suit;
}

int Card::getValue() const
{
	return value;
}

void Card::setValue(int value)
{
	this->value = value;
}

std::string Card::getRank() const
{
	return rank;
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