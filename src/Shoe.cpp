#include "Shoe.hpp"
#include <random>
#include <algorithm>
#include <stdexcept>
void Shoe::shuffle(){
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(shoe_.begin(), shoe_.end(), g);
}

Card Shoe::drawNext(){
    if (shoe_.empty()) {
        throw std::runtime_error("Cannot draw from an empty shoe");
    }

    Card nextCard = shoe_.at(shoe_.size()-1);
    //remove the element
    shoe_.pop_back();
    return nextCard;

}

Shoe::Shoe(int numOfDecks){
    numOfDecks_ = numOfDecks;
    for(int i =0;i < numOfDecks_; i++){
        for(int s = 0; s < 4; s++){
            Suit suit =static_cast<Suit>(s);
            for(int r = 0; r< 13; r++){
                Rank rank = static_cast<Rank>(r);
                Card c = Card(suit, rank);
                shoe_.push_back(c);
            }
        }
    }
    shuffle();

}

int Shoe::cardsRemaining() const{
    return shoe_.size();
}