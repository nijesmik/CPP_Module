#include "Zombie.hpp"

int main(void) {
	randomChump("zombie_1");

	Zombie *zombie = newZombie("zombie_2");
	zombie->announce();
	delete zombie;

	return 0;
}
