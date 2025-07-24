#include <iostream>

#include <cstdlib>

#include <ctime>

#include "Character.h"

#include "CharacterFunction.h"
#include "../spr-labs-MrProperlyHood36/Lab 6 - School Builder/Lab/Helper.h"

int main()
{
    using namespace CharacterFunctions;

    // ======== PART 1 – Functional Tests ========
    Character testHero = CreateCharacter("Blade", 100, 20);
    Character testVillain = CreateCharacter("Reign", 80, 15);

    std::cout << "--- Functional Tests (Part 1) ---\n";
    PrintStats(testHero);
    PrintStats(testVillain);

    std::cout << "\n--- Blade attacks Reign ---\n";
    testVillain = Attack(testHero, testVillain);
    PrintStats(testVillain);

    std::cout << "\n--- Blade heals ---\n";
    testHero = Heal(testHero, 10);
    PrintStats(testHero);

    std::cout << "\n--- Blade Inventory ---\n";
    testHero = AddItem(testHero, "Katana");
    testHero = AddItem(testHero, "Health Potion");
    DisplayInventory(testHero);

    std::cout << "\n--- Coin Flip ---\n";
    bool flip = Helper::CoinFlip();
    std::cout << "Result: " << (flip ? "Heads" : "Tails") << "\n\n";

    // ======== PART 2 – Bad RPG Simulation ========
    std::cout << "Welcome to Bad RPG\n\n";

    srand(static_cast<unsigned int>(time(NULL))); // Only seed once

    Character rpgHero = CreateCharacter("Example Hero", 60, 15);
    Character rpgVillain = CreateCharacter("Example Villain", 60, 15);

    // Add hero items
    rpgHero = AddItem(rpgHero, "Hunting Knife");
    rpgHero = AddItem(rpgHero, "Wooden Shield");
    rpgHero = AddItem(rpgHero, "Health Potion");
    rpgHero = AddItem(rpgHero, "Mana Potion");
    rpgHero = AddItem(rpgHero, "Golden Key");

    // Add villain items
    rpgVillain = AddItem(rpgVillain, "Copper Shortsword");
    rpgVillain = AddItem(rpgVillain, "Poison Potion");
    rpgVillain = AddItem(rpgVillain, "Life Journal");

    // Show initial stats and inventories
    PrintStats(rpgHero);
    std::cout << "Example Hero's Inventory:\n";
    DisplayInventory(rpgHero);
    std::cout << "\n";

    PrintStats(rpgVillain);
    std::cout << "Example Villain's Inventory:\n";
    DisplayInventory(rpgVillain);
    std::cout << "\n";

    // Begin RPG loop
    while (rpgHero.health > 0 && rpgVillain.health > 0)
    {
        bool heroAttacks = Helper::CoinFlip();
        bool heroHeals = Helper::CoinFlip();
        int healAmount = (rand() % 5) + 1;

        if (heroAttacks)
        {
            std::cout << "\nAttacking: Example Hero attacks Example Villain with "
                << rpgHero.attackPower << " attack power.\n";
            rpgVillain = Attack(rpgHero, rpgVillain);
            std::cout << "Example Villain HP: " << rpgVillain.health << "\n";
        }
        else
        {
            std::cout << "\nAttacking: Example Villain attacks Example Hero with "
                << rpgVillain.attackPower << " attack power.\n";
            rpgHero = Attack(rpgVillain, rpgHero);
            std::cout << "Example Hero HP: " << rpgHero.health << "\n";
        }

        if (heroHeals)
        {
            rpgHero = Heal(rpgHero, healAmount);
            std::cout << "Example Hero was healed with " << healAmount << " hit points.\n";
        }
        else
        {
            rpgVillain = Heal(rpgVillain, healAmount);
            std::cout << "Example Villain was healed with " << healAmount << " hit points.\n";
        }
    }

    // Final Output
    std::cout << "\nFinal Result:\n";
    std::cout << "Example Hero\tHP: " << rpgHero.health << "\n";
    std::cout << "Example Villain\tHP: " << rpgVillain.health << "\n";

    std::cout << "\nWinner of Bad RPG:\t"
        << (rpgHero.health > 0 ? "Example Hero" : "Example Villain") << "\n";

    return 0;
}
