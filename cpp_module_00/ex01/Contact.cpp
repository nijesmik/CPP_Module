#include "Contact.h"

Contact::Contact() {
	std::cout << "Enter a first name : ";
	std::getline(std::cin, fisrtName);

	std::cout << "Enter a last name : ";
	std::getline(std::cin, lastName);

	std::cout << "Enter a nickname : ";
	std::getline(std::cin, nickname);

	std::cout << "Enter a phone number : ";
	std::getline(std::cin, phoneNumber);

	std::cout << "Enter a darkest secret : ";
	std::getline(std::cin, darkestSecret);

	next = NULL;
}

std::string Contact::getData(std::string data) {
	if (data.length() > 10) {
		return data.substr(0, 9).append(1, '.');
	}
	return data;
}

std::string Contact::mapToData(int index) {
	if (index == 0) {
		return getData(fisrtName);
	}
	if (index == 1) {
		return getData(lastName);
	}
	return getData(nickname);
}

void Contact::show(int index, std::string delimiter) {
	std::cout << delimiter << std::setw(10) << index << delimiter;

	for (int i = 0; i < 3; i++) {
		std::cout << std::setw(10) << mapToData(i) << delimiter;
	}

	std::cout << std::endl;
}
