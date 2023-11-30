#include "PhoneBook.h"

PhoneBook::PhoneBook() {
	firstContact = NULL;
	lastContact = NULL;
	count = 0;
}

bool PhoneBook::requestCommand() {
	std::cout << "ENTER A COMMAND IN UPPERCASE : ";
	std::string command;
	std::getline(std::cin, command);
	if (!command.compare("ADD")) {
		add();
		return true;
	}
	if (!command.compare("SEARCH")) {
		search();
		return true;
	}
	if (!command.compare("EXIT")) {
		return false;
	}
	std::cout << "WRONG COMMAND.\n";
	return true;
}

void PhoneBook::add() {
	Contact *contact = new Contact();
	if (count++ == 0) {
		firstContact = contact;
	} else {
		lastContact->next = contact;
	}
	lastContact = contact;

	if (count > 8) {
		firstContact = firstContact->next;
	}

	std::cout << "Successfully added a contact!\n";
}

bool PhoneBook::validate(std::string input) {
	bool isValid = true;
	if ((input.length() > 1)
		|| (input[0] < '1' || input[0] > '8')
		|| ((int) (input[0] - '0') > count)) {
		isValid = false;
		std::cout << "Invalid index. Try again.\n";
	}
	return isValid;
}

void PhoneBook::search() {
	std::string input;
	do {
		std::cout << "Enter an index between 1 and 8 : ";
		std::getline(std::cin, input);
	} while (!validate(input));

	std::string delimiter = " | ";
	std::cout << delimiter << std::setw(10) << "index" << delimiter
			  << std::setw(10) << "first name" << delimiter
			  << std::setw(10) << "last name" << delimiter
			  << std::setw(10) << "nickname" << delimiter << std::endl
			  << " | ---------- | ---------- | ---------- | ---------- | " << std::endl;

	Contact *contact = firstContact;
	int index = input[0] - '0';
	for (int i = 1; i < index; i++) {
		contact = contact->next;
	}
	contact->show(index, delimiter);
}
