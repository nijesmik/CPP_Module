#ifndef CPP_MODULE_HUMANA_HPP
#define CPP_MODULE_HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
public:
	HumanA(std::string name, Weapon &weapon);

	void attack();

private:
	Weapon *weapon;
	std::string name;
};


#endif
