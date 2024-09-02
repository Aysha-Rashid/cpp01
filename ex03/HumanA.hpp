#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA {
private:
    std::string name;
    Weapon& weapon;

public:
    HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon) {}

    void attack() const {
        std::cout << name << " attacks with their " << weapon.getType() << std::endl;
    }
};

#endif
