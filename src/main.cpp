#include <iostream>
#include <stdexcept>
#include "Card.hpp"
#include "Hand.hpp"
#include "Shoe.hpp"

int main() {
    std::cout << std::boolalpha;

    // =========================
    // 1. Known hand tests
    // =========================
    std::cout << "=== Known Hand Tests ===\n";

    // Hand 1: Blackjack (Ace + King)
    Hand hand1;
    hand1.addCard(Card(Suit::Hearts, Rank::Ace));
    hand1.addCard(Card(Suit::Spades, Rank::King));

    std::cout << "Hand 1: Ace of Hearts, King of Spades\n";
    std::cout << "  total:       " << hand1.total() << "\n";
    std::cout << "  isBust:      " << hand1.isBust() << "\n";
    std::cout << "  isBlackjack: " << hand1.isBlackjack() << "\n";
    std::cout << "  isSoft:      " << hand1.isSoft() << "\n\n";

    // Hand 2: 9 + 7 + 6 = 22 (bust)
    Hand hand2;
    hand2.addCard(Card(Suit::Clubs, Rank::Nine));
    hand2.addCard(Card(Suit::Diamonds, Rank::Seven));
    hand2.addCard(Card(Suit::Hearts, Rank::Six));

    std::cout << "Hand 2: 9 of Clubs, 7 of Diamonds, 6 of Hearts\n";
    std::cout << "  total:       " << hand2.total() << "\n";
    std::cout << "  isBust:      " << hand2.isBust() << "\n";
    std::cout << "  isBlackjack: " << hand2.isBlackjack() << "\n";
    std::cout << "  isSoft:      " << hand2.isSoft() << "\n\n";

    // Hand 3: Soft 17 (Ace + 6)
    Hand hand3;
    hand3.addCard(Card(Suit::Hearts, Rank::Ace));
    hand3.addCard(Card(Suit::Clubs, Rank::Six));

    std::cout << "Hand 3: Ace of Hearts, 6 of Clubs\n";
    std::cout << "  total:       " << hand3.total() << "\n";
    std::cout << "  isBust:      " << hand3.isBust() << "\n";
    std::cout << "  isBlackjack: " << hand3.isBlackjack() << "\n";
    std::cout << "  isSoft:      " << hand3.isSoft() << "\n\n";


    // =========================
    // 2. Random draws from a Shoe
    // =========================
    std::cout << "=== Random Draws from Shoe ===\n";

    int numDecks = 1;
    Shoe shoe(numDecks);  // constructor already shuffles

    std::cout << "Initial cards remaining in shoe: "
              << shoe.cardsRemaining() << "\n";

    Hand randomHand;
    for (int i = 0; i < 5; ++i) {
        Card c = shoe.drawNext();
        randomHand.addCard(c);
        std::cout << "  Drew: " << c.toString() << "\n";
    }

    std::cout << "Random hand total: " << randomHand.total() << "\n";
    std::cout << "isBust: " << randomHand.isBust()
              << ", isSoft: " << randomHand.isSoft() << "\n";
    std::cout << "Cards remaining after 5 draws: "
              << shoe.cardsRemaining() << "\n\n";


    // =========================
    // 3. Edge case: run out of cards mid-hand
    // =========================
    std::cout << "=== Edge Case: Run Out of Cards Mid-Hand ===\n";

    // We will keep dealing "hands" of up to 10 cards each
    // Eventually the 1-deck shoe will run out, and we'll:
    // - detect the exception
    // - void the current hand
    // - reset to a new full shoe
    // - continue
    for (int round = 1; round <= 15; ++round) {
        std::cout << "\nRound " << round << ":\n";
        Hand roundHand;
        bool handValid = true;

        for (int i = 0; i < 10; ++i) {
            try {
                Card c = shoe.drawNext();
                roundHand.addCard(c);
                std::cout << "  Drew: " << c.toString() << "\n";
            } catch (const std::runtime_error& e) {
                std::cout << "  [Shoe empty while dealing card "
                          << (i + 1) << " of this hand. "
                          << "Voiding hand and resetting shoe.]\n";

                handValid = false;
                roundHand.clear();

                // Reset shoe to a brand new, full, shuffled shoe
                shoe = Shoe(numDecks);
                std::cout << "  New shoe created. Cards remaining: "
                          << shoe.cardsRemaining() << "\n";
                break;
            }
        }

        if (handValid) {
            std::cout << "  Hand total: " << roundHand.total()
                      << ", isBust: " << roundHand.isBust()
                      << ", isBlackjack: " << roundHand.isBlackjack()
                      << ", isSoft: " << roundHand.isSoft() << "\n";
        } else {
            std::cout << "  Hand was voided due to empty shoe.\n";
        }

        std::cout << "  Cards remaining in shoe: "
                  << shoe.cardsRemaining() << "\n";
    }

    return 0;
}
