#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanA
{
	private:
		std::string name;
		Weapon &weapon;

	public:
		HumanA(const std::string &localname, Weapon &localweapon);
		~HumanA();
		void attack();
};

#endif
