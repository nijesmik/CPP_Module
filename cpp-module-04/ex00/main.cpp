//
// Created by 김세진 on 5/11/24.
//

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
    const Animal *animal = new Animal();
    const Animal *dog = new Dog();
    const Animal *cat = new Cat();
    const WrongAnimal *wrongAnimal = new WrongAnimal();
    const WrongCat *wrongCat = new WrongCat();
    const WrongAnimal *wrongCat2 = wrongCat;
    std::cout << std::endl;

    animal->makeSound();
    dog->makeSound();
    cat->makeSound();
    std::cout << std::endl;

    wrongAnimal->makeSound();
    wrongCat->makeSound();
    wrongCat2->makeSound();
    std::cout << std::endl;

    delete animal;
    delete dog;
    delete cat;
    delete wrongAnimal;
    delete wrongCat;

    return 0;
}