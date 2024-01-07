#include "Contact.h"

Contact::Contact() {}

Contact::Contact(std::string input[5]) {
	firstName = input[0];
	lastName = input[1];
	nickname = input[2];
	phoneNumber = input[3];
	darkestSecret = input[4];
}

std::string Contact::getData(std::string data) {
	if (data.length() > 10) {
		return data.substr(0, 9).append(1, '.');
	}
	return data;
}

std::string Contact::mapToData(int index) {
	if (index == 0) {
		return getData(firstName);
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
