//
// Created by Sejin Kim on 7/8/24.
//

#include <ctime>
#include <cstdlib>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
    switch (std::rand() % 3) {
        case 0:
            return new A();
        case 1:
            return new B();
        default:
            return new C();
    }
}

void identify(Base *p) {
    if (dynamic_cast<A *>(p)) {
        std::cout << "A" << std::endl;
        return;
    }
    if (dynamic_cast<B *>(p)) {
        std::cout << "B" << std::endl;
        return;
    }
    if (dynamic_cast<C *>(p)) {
        std::cout << "C" << std::endl;
        return;
    }
    std::cout << "Unknown" << std::endl;
}

void identify(Base &p) {
    try {
        (void) dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (std::exception &e) {}

    try {
        (void) dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (std::exception &e) {}

    try {
        (void) dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (std::exception &e) {}

    std::cout << "Unknown" << std::endl;
}

int main() {
    std::srand(std::time(0));

    Base *p = generate();
    identify(p);
    identify(*p);
    delete p;

    return 0;
}
