#include <iostream>

class Megaphone {
private:
    char **messages;

    char *_toUpper(char *message);

public:
    Megaphone(char **message);

    void printMessage();
};

Megaphone::Megaphone(char **messages) {
    this->messages = messages;
}

char *Megaphone::_toUpper(char *message) {
    int i = 0;
    while (message[i]) {
        if ('a' <= message[i] && message[i] <= 'z') {
            message[i] += 'A' - 'a';
        }
        i++;
    }
    return message;
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