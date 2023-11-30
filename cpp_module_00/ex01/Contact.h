#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>
#include <iomanip>

class Contact {
private:
	std::string fisrtName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	std::string mapToData(int index);

	std::string getData(std::string data);

public:
	Contact *next;

	Contact();

	void show(int index, std::string delimiter);
};

#endif //CONTACT_H
