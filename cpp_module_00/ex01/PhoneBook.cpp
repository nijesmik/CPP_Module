#include "PhoneBook.h"

PhoneBook::PhoneBook() {
	firstContact = NULL;
	lastContact = NULL;
	count = 0;
}

bool PhoneBook::requestCommand() {
	std::cout << "ENTER A COMMAND IN UPPERCASE : ";
	std::string command;
	std::cin >> command;
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

void PhoneBook::search() {
	std::cout << "| .....index | first name | .last name | ..nickname |" << std::endl;
	std::cout << "| ---------- | ---------- | ---------- | ---------- |" << std::endl;

	Contact *contact = firstContact;
	int index = 1;
	while (contact) {
		contact->show(index++);
		contact = contact->next;
	}
}
