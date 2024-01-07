#include <iostream>

class Megaphone {
private:
    char **messages;

    std::string _toUpper(char *message);

public:
    Megaphone(char **message);

    void printMessage();
};

Megaphone::Megaphone(char **messages) {
    this->messages = messages;
}

std::string Megaphone::_toUpper(char *message) {
    std::string str;
    int i = 0;
    while (message[i]) {
        str.append(1, (char) std::toupper(message[i]));
        i++;
    }
    return str;
}

void Megaphone::printMessage() {
    if (!*messages) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return;
    }
    int idx = 0;
    while (messages[idx]) {
        std::cout << _toUpper(messages[idx]);
        idx++;
    }
    std::cout << std::endl;
}

int main(int ac, char **av) {
    (void) ac;
    Megaphone megaphone(av + 1);
    megaphone.printMessage();
}