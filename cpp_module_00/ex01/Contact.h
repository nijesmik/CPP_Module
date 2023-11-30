#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>

class Contact {
private:
	std::string fisrtName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	std::string mapIdxToData(int idx);

public:
	Contact *next;

	Contact();

	void show(int index);
};

#endif //CONTACT_H
