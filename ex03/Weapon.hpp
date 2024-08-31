#include <iostream>
#include <string.h>
#include "HumanA.hpp"
#include "HumanB.hpp"

class Weapon
{
    private:
        std::string type;
    void getType();
    void setType();
    Weapon(std::string weaponType);
    ~Weapon();
};