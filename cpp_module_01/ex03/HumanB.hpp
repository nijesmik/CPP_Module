#ifndef CPP_MODULE_HUMANB_HPP
#define CPP_MODULE_HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
public:
	HumanB(std::string name);

	void attack();

	void setWeapon(Weapon &weapon);

private:
	Weapon *weapon;
	std::string name;
};

#endif
