#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>
#include <iomanip>

class Contact {
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

	std::string mapToData(int index);

	std::string getData(std::string data);

public:
	Contact();

	Contact(std::string input[5]);

	void show(int index, std::string delimiter);
};

#endif //CONTACT_H
