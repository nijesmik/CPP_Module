#include "PhoneBook.h"

PhoneBook::PhoneBook() {
	count = 0;
}

std::string PhoneBook::getline() {
	std::string str;
	std::getline(std::cin, str);
	if (std::cin.fail()) {
		std::cin.clear();
		std::clearerr(stdin);
	}
	return str;
}

bool PhoneBook::requestCommand() {
	std::cout << "ENTER A COMMAND IN UPPERCASE : ";
	std::string command = getline();
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
	std::cout << "WRONG COMMAND." << std::endl;
	return true;
}

bool PhoneBook::validateInput(std::string input) {
	if (!input.length()) {
		std::cout << std::endl;
		return false;
	}
	return true;
}

void PhoneBook::add() {
	std::string message[5];
	std::string input[5];
	message[0] = "Enter a first name : ";
	message[1] = "Enter a last name : ";
	message[2] = "Enter a nickname : ";
	message[3] = "Enter a phone number : ";
	message[4] = "Enter a darkest secret : ";

	int i = 0;
	do {
		std::cout << message[i];
		input[i] = getline();
		if (validateInput(input[i])) {
			i++;
		}
	} while (i < 5);

	Contact contact(input);
	int index = count % 8;
	contacts[index] = contact;
	count++;
	std::cout << "Successfully added a contact!" << std::endl;
}

bool PhoneBook::validateIndexInput(std::string input) {
	if (input.length() > 1) {
		std::cout << "Invalid index. Try again." << std::endl;
		return false;
	}
	int index = input[0] - '0';
	if (index < 1 || index > 8 || (count < 8 && index > count)) {
		std::cout << "Invalid index. Try again." << std::endl;
		return false;
	}
	return true;
}

void PhoneBook::search() {
	if (count == 0) {
		std::cout << "NO CONTACT." << std::endl;
		return;
	}

	showColumn();
	int n = count;
	if (count > 8) {
		n = 8;
	}
	for (int i = 0; i < n; i++) {
		contacts[i].show(i + 1, DELIMITER);
	}

	std::string input;
	do {
		std::cout << "Enter an index between 1 and 8 : ";
		input = getline();
	} while (!validateIndexInput(input));

	showColumn();
	int index = input[0] - '0';
	contacts[index - 1].show(index, DELIMITER);
}

void PhoneBook::showColumn() {
	std::cout << DELIMITER << std::setw(10) << "index" << DELIMITER
			  << std::setw(10) << "first name" << DELIMITER
			  << std::setw(10) << "last name" << DELIMITER
			  << std::setw(10) << "nickname" << DELIMITER << std::endl
			  << " | ---------- | ---------- | ---------- | ---------- | " << std::endl;
}
