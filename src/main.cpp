#include <iostream>
#include "Card.hpp"

int main() {
    // Create a few cards
    Card c1(Suit::Hearts, Rank::Ace);
    Card c2(Suit::Spades, Rank::Ten);
    Card c3(Suit::Clubs, Rank::Jack);

    // Print them
    std::cout << c1.toString() << '\n';
    std::cout << c2.toString() << '\n';
    std::cout << c3.toString() << '\n';

    // Test getters
    std::cout << "c1 suit: " << toString(c1.getSuit())
              << ", rank: " << toString(c1.getRank()) << '\n';

    // Test setters (just for sanity)
    c3.setSuit(Suit::Diamonds);
    c3.setRank(Rank::Queen);
    std::cout << "After setters, c3: " << c3.toString() << '\n';

    return 0;
}
