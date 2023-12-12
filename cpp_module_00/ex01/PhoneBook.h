#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iomanip>
#include <iostream>
#include <string>
#include "Contact.h"

#define DELIMITER " | "

class PhoneBook {
private:
	int count;
	Contact contacts[8];

	void add();

	void search();

	bool validateIndexInput(std::string input);

	bool validateInput(std::string input);

	void showColumn();

	std::string getline();

public:
	PhoneBook();

	bool requestCommand();
};


#endif //PHONEBOOK_H
