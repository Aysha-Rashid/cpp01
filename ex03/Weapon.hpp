#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
private:
    std::string type;

public:
    Weapon(const std::string& type) : type(type) {}

    const std::string& getType() const {
        return type;
    }

    void setType(const std::string& newType) {
        type = newType;
    }
};

#endif
