#include <iostream>
#include "Hand.hpp"

void Hand::addCard(const Card& card){
    cards.push_back(card);
}
void Hand::clear(){
    cards.clear();
}
int Hand::total() const{
    int count = 0;
    int aceCount = 0;
    for(int i = 0; i < cards.size(); i++){
        const Card& currCard = cards.at(i);
        Rank currRank = currCard.getRank();
        if (currRank == Rank::Ace){
            count += 11;
            aceCount++;
        }else if (currRank == Rank::Three) {
            count +=3;
        } else if (currRank == Rank::Four) {
            count +=4;
        } else if (currRank == Rank::Five) {
            count +=5;
        } else if (currRank == Rank::Six) {
            count +=6;
        } else if (currRank == Rank::Seven) {
            count +=7;
        } else if (currRank == Rank::Eight) {
            count +=8;
        } else if (currRank == Rank::Nine) {
            count +=9;
        } else if (currRank == Rank::Two) {
            count +=2;
        } else{
            count +=10;
        }
        
    }
    while ((count > 21) && (aceCount > 0)){
        count -=10;
        aceCount--;
    }
    return count;

}
bool Hand::isBust() const{
    return(total() > 21);
}
bool Hand::isBlackjack() const{
    if (cards.size() == 2 && total()== 21){
        return true;
    }
    else{
        return false;
    }
}
bool Hand::isSoft() const{
    int count = 0;
    int aceCount = 0;
    for(int i = 0; i < cards.size(); i++){
        const Card& currCard = cards.at(i);
        Rank currRank = currCard.getRank();
        if (currRank == Rank::Ace){
            count += 11;
            aceCount++;
        }else if (currRank == Rank::Three) {
            count +=3;
        } else if (currRank == Rank::Four) {
            count +=4;
        } else if (currRank == Rank::Five) {
            count +=5;
        } else if (currRank == Rank::Six) {
            count +=6;
        } else if (currRank == Rank::Seven) {
            count +=7;
        } else if (currRank == Rank::Eight) {
            count +=8;
        } else if (currRank == Rank::Nine) {
            count +=9;
        } else if (currRank == Rank::Two) {
            count +=2;
        } else{
            count +=10;
        }
        
    }
    while ((count > 21) && (aceCount > 0)){
        count -=10;
        aceCount--;
    }
    return aceCount > 0;
}