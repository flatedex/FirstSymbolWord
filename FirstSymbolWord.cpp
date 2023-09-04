#include <iostream>
#include <vector>
#include <sstream>

const char DELIMITER = ' ';

void Split(std::string text, std::vector<std::string>& collection) {
    std::string temp = "";

    for (int i = 0; i < static_cast<int>(text.size()); i++) {
        if (text[i] != DELIMITER) {
            temp += text[i];
        }
        else {
            collection.push_back(temp);
            temp = "";
        }
    }
}

std::string FindWord(std::string text, char symbol) {

    std::vector<std::string> words(text.size() / 2 + 1);

    Split(text, words);

    for (auto& item : words) { // erase empty elements from vector
        if (item.empty()) {
            words.erase(words.begin());
        }
    }

    for (auto& item : words) {
        if (item[0] == symbol) {
            return item;
        }
    }
    
    return "";
}

int main()
{
    bool exitStatus = true;

    std::string text = "";
    std::string answer = "";
    char symbol;
    std::cout << "Enter your text: " << std::endl;
    std::getline(std::cin, text);

    std::cout << "Enter your symbol: " << std::endl;
    std::cin >> symbol;

    answer = FindWord(text, symbol);
    if (answer != "") {
        std::cout << answer + " is what you were finding for!" << std::endl;
    }
    else {
        std::cout << "There is no such word that begins with " + symbol << std::endl;
    }
    
}
