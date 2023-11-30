#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iomanip>
#include <iostream>
#include <string>
#include "Contact.h"

class PhoneBook {
private:
	Contact *firstContact;
	Contact *lastContact;
	int count;

	void add();

	void search();

	bool validate(std::string input);

public:
	PhoneBook();

	bool requestCommand();
};


#endif //PHONEBOOK_H
