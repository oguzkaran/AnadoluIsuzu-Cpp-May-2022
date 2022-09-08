/*----------------------------------------------------------------------------------------------------------------------
    Card sınıfı
----------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include "game/Card.hpp"

int main()
{
    using namespace std;
    using org::csystem::game::card::Card;
    using org::csystem::game::card::shuffleDeck;
    using org::csystem::game::card::getDeck;

    auto deck{getDeck()};
    shuffleDeck<200>(deck);

    for (auto &c : deck)
        cout << c << '\n';

    cout << "-----------------------------------------------------\n";

    shuffleDeck<100>(deck);

    for (auto &c : deck)
        cout << c << '\n';

    cout << "-----------------------------------------------------\n";


    return 0;
}

