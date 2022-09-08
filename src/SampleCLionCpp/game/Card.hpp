#ifndef CARD_HPP_
#define CARD_HPP_

#include <iostream>
#include <string>
#include <array>
#include "../csd/utility.hpp"

namespace org::csystem::game::card {
    class Card;
    std::array<Card, 52> fillDeck(std::array<Card, 52> &deck);
    std::array<Card, 52> getDeck();
    std::array<Card, 52> getShuffledDeck();
    template <std::size_t N>
    std::array<Card, 52> shuffleDeck(std::array<Card, 52> &deck);

    enum class CardType {Spade, Club, Diamond, Heart};
    enum class CardValue {Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Knave, Queen, King, Ace};

    class Card {
        friend std::ostream &operator<<(std::ostream &os, const Card &c);
    private:
        CardType m_type;
        CardValue m_value;
    public:
        constexpr Card() = default;
        constexpr Card(CardType type, CardValue value) : m_type{type}, m_value{value}
        {}
    public:
        constexpr CardType type() const {return m_type;}
        constexpr CardValue value() const {return m_value;}
        constexpr  void type(CardType type) {m_type = type;}
        constexpr  void value(CardValue value) {m_value = value;}

        //...

        std::string toStr() const;
    };

    template <std::size_t N>
    std::array<Card, 52> shuffleDeck(std::array<Card, 52> &deck)
    {
        using org::csystem::util::algorithm::csdShuffle;

        csdShuffle<N>(deck.begin(), deck.end());

        return deck;
    }
}


#endif //CARD_HPP_
