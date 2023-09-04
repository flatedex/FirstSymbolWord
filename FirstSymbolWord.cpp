#include <iostream>

const char DELIMITER = ' ';

int main()
{
    bool exitStatus = true;

    std::string text = "";
    std::string answer = "";
    char symbol;
    std::cin >> text >> symbol;

    answer = FindWord(text, symbol);

    std::cout << answer << std::endl;
}
std::string FindWord(std::string text, char symbol) {
    for (auto piece : text) {
        if (piece == symbol) {
            break;
        }
    }
    return text;
}
std::string WordConstructor(std::string text) {
    for (auto piece : text) {

    }
    return text;
}