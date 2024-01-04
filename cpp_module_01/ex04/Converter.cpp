#include "Converter.hpp"

void Converter::convert(std::string fileName, std::string s1, std::string s2) {
	std::ifstream input(fileName);
	if (!input.is_open()) {
		std::cerr << "File open failed!" << std::endl;
		return;
	}

	std::string newFileName = fileName + ".replace";
	std::ofstream output(newFileName, std::ios_base::trunc);
	if (!output.is_open()) {
		std::cerr << "Cannot create file!" << std::endl;
		return;
	}

	std::string line;
	while (std::getline(input, line)) {
		if (!input.eof()) {
			line += "\n";
		}
		size_t pos = line.find(s1);
		while (pos != std::string::npos) {
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos = line.find(s1, pos + s2.length());
		}
		output << line;
	}

	input.close();
	output.close();

	std::cout << "Replacement complete!" << std::endl;
}

void Converter::convert(char *fileName, char *s1, char *s2) {
	std::string _fileName(fileName);
	std::string _s1(s1);
	std::string _s2(s2);
	convert(_fileName, _s1, _s2);
}
