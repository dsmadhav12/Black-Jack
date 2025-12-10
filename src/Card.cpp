#include <iostream>
#include "Card.hpp"

std::string toString(Suit suit){
    if (suit == Suit::Hearts){
        return "Hearts";
    }
    else if (suit == Suit::Diamonds){
        return "Diamonds";
    }
    else if (suit == Suit::Spades){
        return "Spades";
    }
    else if (suit == Suit::Clubs){
        return "Clubs";
    }
    else {
        return "Error!";
    }
}

std::string toString(Rank rank) {
    if (rank == Rank::Two) {
        return "2";
    } else if (rank == Rank::Three) {
        return "3";
    } else if (rank == Rank::Four) {
        return "4";
    } else if (rank == Rank::Five) {
        return "5";
    } else if (rank == Rank::Six) {
        return "6";
    } else if (rank == Rank::Seven) {
        return "7";
    } else if (rank == Rank::Eight) {
        return "8";
    } else if (rank == Rank::Nine) {
        return "9";
    } else if (rank == Rank::Ten) {
        return "10";
    } else if (rank == Rank::Jack) {
        return "Jack";
    } else if (rank == Rank::Queen) {
        return "Queen";
    } else if (rank == Rank::King) {
        return "King";
    } else if (rank == Rank::Ace) {
        return "Ace";
    }

    return "Error";
}

Card::Card(Suit suit, Rank rank){
    suit_ = suit;
    rank_ = rank;
}

Suit Card::getSuit() const{
    return suit_;
}

Rank Card::getRank() const{
    return rank_;
}

//Setters

void Card::setSuit(Suit suit){
    suit_ = suit;
}
void Card::setRank(Rank rank){
    rank_ = rank;
}


//The ::before the two strings tells the compiler that it wants to use the global one instead of the Card one
std::string Card::toString() const{
    return ::toString(rank_) + " of "+ ::toString(suit_);
}

