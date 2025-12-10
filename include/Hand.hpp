#ifndef HAND_HPP
#define HAND_HPP

#include "Card.hpp"
#include <vector>
//dont use namepsace for header files as they leak into other files that use said header
//using namespace std;

class Hand{
    //methods
    public:
        //prevents a "double copy when compared to Card card"
        void addCard(const Card& card);
        void clear();
        int total() const;
        bool isBust() const;
        bool isBlackjack() const;
        bool isSoft() const;



    private:
        std::vector<Card> cards;
};

#endif