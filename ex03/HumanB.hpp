#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB {
private:
    std::string name;
    Weapon* weapon;  // Pointer to allow no weapon initially

public:
    HumanB(const std::string& name) : name(name), weapon(NULL) {}

    void setWeapon(Weapon& newWeapon) {
        weapon = &newWeapon;
    }

    void attack() const {
        if (weapon) {
            std::cout << name << " attacks with their " << weapon->getType() << std::endl;
        } else {
            std::cout << name << " has no weapon!" << std::endl;
        }
    }
};

#endif
