#ifndef CARD_HPP
#define CARD_HPP

//needed inorder to use string type and methods
#include <string>
//bad practice to put name space into headers as the actual cpp file inherts it
//using namespace std;

enum class Suit {
    Hearts,
    Clubs,
    Diamonds,
    Spades
};

enum class Rank {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace
};

//ToString for just Rank and Suit

std::string toString(Suit suit);
std::string toString(Rank rank);

class Card {
    public:
        //Constructor
        Card(Suit suit, Rank rank);
        //getters and setters
        Suit getSuit() const;
        Rank getRank() const;

        //setter which will never be used in the scope of blackjack but here for learning purposes
        void setSuit(Suit suit);
        void setRank(Rank rank);

        //to string for the whole card

        std::string toString() const;

    private:
        //Data members: where Each Card type stores suit and rank
        Suit suit_;
        Rank rank_;
    
};






#endif