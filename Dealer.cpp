#include "Dealer.hpp"
#include <stdexcept>

void Dealer::addCard(Card card) {
    dealerHand.push_back(card);
}

int Dealer::getHandValue() const {
    int totalValue = 0;
    int aceCount = 0;

    for (const Card& card : dealerHand) {
        totalValue += card.getValue();
        if (card.getRank() == "Ace") {
            aceCount++;
        }
    }

    // Adjust for Aces
    while (totalValue > 21 && aceCount > 0) {
        totalValue -= 10;
        aceCount--;
    }

    return totalValue;
}

bool Dealer::hasBlackJack(Dealer dealer) {
    if (dealer.getHandValue() == 21) {
        return true;
    }
    else {
        return false;
    }
}

int Dealer::getHandSize() {
	return dealerHand.size();
}

Card Dealer::getCard(int index) {
    if (index >= 0 && index < static_cast<int>(dealerHand.size())) {
        return dealerHand[index];
    }
    throw std::out_of_range("Dealer hand index out of range");
}

void Dealer::hit(Deck& deck) {
    dealerHand.push_back(deck.drawCard());
}

void Dealer::clearHand() {
    dealerHand.clear();
}


