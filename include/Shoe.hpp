#ifndef SHOE_HPP
#define SHOE_HPP
#include "Card.hpp"
#include <vector>

class Shoe{
    public:
        void shuffle();
        Card drawNext();
        Shoe(int numOfDecks);
        int cardsRemaining() const;
    private:
        int numOfDecks_;
        std::vector<Card> shoe_;


};

#endif