#pragma once
#include "Character.h"

#include <iostream>

namespace CharacterFunctions
{
    Character CreateCharacter(const std::string name, int health, int attackPower)
    {
        return Character{ name, health, attackPower, {} };
    }

    Character Attack(const Character& attacker, const Character& target)
    {
        return Character
        {
            target.name,
            target.health - attacker.attackPower > 0 ? target.health - attacker.attackPower : 0,
            target.attackPower,
            target.inventory
        };
    }

    Character Heal(const Character& character, int amount)
    {
        return Character
        {
            character.name,
            character.health + amount,
            character.attackPower,
            character.inventory
        };
    }

    Character AddItem(const Character& character, const std::string& item)
    {
        Character updated = character;
        updated.inventory.push_back(item);
        return updated;
    }

    void DisplayInventory(const Character& character)
    {
        std::cout << character.name << "'s Inventory:\n";
        for (const auto& item : character.inventory)
        {
            std::cout << "- " << item << "\n";
        }
    }

    void PrintStats(const Character& character)
    {
        std::cout << "Name: " << character.name << "\n";
        std::cout << "Health: " << character.health << "\n";
    }
}
