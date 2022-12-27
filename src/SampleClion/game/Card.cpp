#include "Card.hpp"

namespace org::csystem::game::card {

    std::array<Card, 52> fillDeck(std::array<Card, 52> &deck)
    {
        std::size_t i{};

        for (std::size_t ti{}; ti < 4; ++ti)
            for (std::size_t vi{}; vi < 13; ++vi)
                deck[i++] = Card{static_cast<CardType>(ti), static_cast<CardValue>(vi)};

        return deck;
    }

    std::array<Card, 52> getDeck()
    {
        using std::array;

        array<Card, 52> deck{};

        return fillDeck(deck);
    }

    std::array<Card, 52> getShuffledDeck()
    {
        auto deck{getDeck()};
        return shuffleDeck<100>(deck);
    }

    std::ostream &operator<<(std::ostream &os, const Card &c)
    {
        return os << c.toStr();
    }

    std::string Card::toStr() const
    {
        using namespace std;

        static array<string, 4> types {"Spade", "Club", "Diamond", "Heart"};
        static array<string, 13> values{"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Knave", "Queen", "King", "Ace"};

        return types[static_cast<int>(m_type)] + "-" + values[static_cast<int>(m_value)];
    }
}
