#ifndef DEALER_HPP
#define DEALER_HPP

#include <vector>
#include "Card.hpp"
#include "Deck.hpp"

class Dealer {
public:
    Dealer() = default;

    void addCard(Card card);
    int getHandValue() const;
    Card getCard(int index);
    void hit(Deck& deck);
    void clearHand();
    bool hasBlackJack(Dealer dealer);
    int getHandSize();

private:
    std::vector<Card> dealerHand;
};

#endif