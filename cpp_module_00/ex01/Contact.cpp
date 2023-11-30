#include "Contact.h"

Contact::Contact() {
	std::cout << "Enter a first name : ";
	std::cin >> fisrtName;

	std::cout << "Enter a last name : ";
	std::cin >> lastName;

	std::cout << "Enter a nickname : ";
	std::cin >> nickname;

	std::cout << "Enter a phone number : ";
	std::cin >> phoneNumber;

	std::cout << "Enter a darkest secret : ";
	std::cin >> darkestSecret;

	next = NULL;
}

std::string Contact::mapIdxToData(int idx) {
	if (idx == 0) {
		return fisrtName.substr(0, 10);
	}
	if (idx == 1) {
		return lastName.substr(0, 10);
	}
	return nickname.substr(0, 10);
}

void Contact::show(int index) {
	std::cout << "| ........." << index << " | ";
	std::string tmp;

	for (int i = 0; i < 3; i++) {
		tmp = mapIdxToData(i);
		std::cout << tmp.insert(0, 10 - tmp.length(), '.') << " | ";
	}

	std::cout << std::endl;
}
