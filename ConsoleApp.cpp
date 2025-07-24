#include <iostream>
#include "Character.h"
#include "CharacterFunction.h"
#include "../spr-labs-MrProperlyHood36/Lab 6 - School Builder/Lab/Helper.h"

int main()
{
    using namespace CharacterFunctions;

    // Create characters
    Character hero = CreateCharacter("Blade", 100, 20);
    Character villain = CreateCharacter("Reign", 80, 15);

    // Display stats
    std::cout << "--- Initial Stats ---\n";
    PrintStats(hero);
    PrintStats(villain);

    // Attack phase
    std::cout << "\n--- Blade attacks Reign ---\n";
    villain = Attack(hero, villain);
    PrintStats(villain);

    // Heal phase
    std::cout << "\n--- Blade uses a medkit ---\n";
    hero = Heal(hero, 10);
    PrintStats(hero);

    // Add inventory items
    std::cout << "\n--- Blade picks up items ---\n";
    hero = AddItem(hero, "Katana");
    hero = AddItem(hero, "Health Potion");


    // Display inventory
    std::cout << "\n--- Blade's Inventory ---\n";
    DisplayInventory(hero);

    // Coin flip
    std::cout << "\n--- Coin Flip ---\n";
    bool flip = Helper::CoinFlip();
    std::cout << "Result: " << (flip ? "Heads" : "Tails") << "\n";

    return 0;
};
