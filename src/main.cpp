#include <iostream>
#include "Card.hpp"
#include "Hand.hpp"

int main() {
    std::cout << std::boolalpha;  // print true/false instead of 1/0

    // -------- Hand 1: Blackjack (Ace + King) --------
    Hand hand1;
    hand1.addCard(Card(Suit::Hearts, Rank::Ace));
    hand1.addCard(Card(Suit::Spades, Rank::King));

    std::cout << "Hand 1: "
              << Card(Suit::Hearts, Rank::Ace).toString() << ", "
              << Card(Suit::Spades, Rank::King).toString() << "\n";
    std::cout << "  total:       " << hand1.total() << "\n";
    std::cout << "  isBust:      " << hand1.isBust() << "\n";
    std::cout << "  isBlackjack: " << hand1.isBlackjack() << "\n";
    std::cout << "  isSoft:      " << hand1.isSoft() << "\n\n";

    // -------- Hand 2: Hard 22 (9 + 7 + 6) → bust --------
    Hand hand2;
    hand2.addCard(Card(Suit::Clubs, Rank::Nine));
    hand2.addCard(Card(Suit::Diamonds, Rank::Seven));
    hand2.addCard(Card(Suit::Hearts, Rank::Six));

    std::cout << "Hand 2: 9 of Clubs, 7 of Diamonds, 6 of Hearts\n";
    std::cout << "  total:       " << hand2.total() << "\n";
    std::cout << "  isBust:      " << hand2.isBust() << "\n";
    std::cout << "  isBlackjack: " << hand2.isBlackjack() << "\n";
    std::cout << "  isSoft:      " << hand2.isSoft() << "\n\n";

    // -------- Hand 3: Soft 17 (Ace + 6) --------
    Hand hand3;
    hand3.addCard(Card(Suit::Hearts, Rank::Ace));
    hand3.addCard(Card(Suit::Clubs, Rank::Six));

    std::cout << "Hand 3: Ace of Hearts, 6 of Clubs\n";
    std::cout << "  total:       " << hand3.total() << "\n";
    std::cout << "  isBust:      " << hand3.isBust() << "\n";
    std::cout << "  isBlackjack: " << hand3.isBlackjack() << "\n";
    std::cout << "  isSoft:      " << hand3.isSoft() << "\n";

    return 0;
}
