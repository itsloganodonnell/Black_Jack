#include "Dealer.hpp"
#include "Card.hpp"

Dealer::Dealer(std::vector<Card> deck) {}

void Dealer::addCard(Card card)
{
    dealerHand.push_back(card);
}
int Dealer::getHandValue() const
{
    int totalValue = 0;
    int aceCount = 0;

    for (const Card& card : dealerHand) {
        int value = card.getValue();
        totalValue += value;

        if (card.getRank() == "Ace") {
            aceCount++;
        }
    }
    while (totalValue > 21 && aceCount > 0) {
        totalValue -= 10;
        aceCount--;
    }

    return totalValue;
}

Card Dealer::getCard(int index) const {
    if (index >= 0 && index < dealerHand.size()) {
        return dealerHand[index];  // Return the card at the given index
    }
    throw std::out_of_range("Index out of range");
}