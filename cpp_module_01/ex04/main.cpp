#include "Converter.hpp"

int main(int ac, char **av) {
	if (ac != 4) {
		std::cerr << "Invalid arguments!" << std::endl;
		return 1;
	}

	Converter converter;
	converter.convert(av[1], av[2], av[3]);

	return 0;
}
