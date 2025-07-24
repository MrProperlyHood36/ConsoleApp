#pragma once
#include <string>
#include <vector>

struct Character
{
    std::string name;
    int health;
    int attackPower;
    std::vector<std::string> inventory;
};

