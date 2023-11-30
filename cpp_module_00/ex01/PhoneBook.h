#ifndef PHONEBOOK_H
#define PHONEBOOK_H

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

public:
	PhoneBook();

	bool requestCommand();
};


#endif //PHONEBOOK_H
