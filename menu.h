#pragma once

#ifdef max
#undef max
#endif

#include "algorithm.h"
#include <string>
#include <iostream>

enum class Menu
{
	YES = 1,
	NO = 2
};

enum class InputType {
	FILE = 1,
	KEYBOARD = 2
};

template <typename T>
T GetInput(void) {
	T input;
	std::cin >> input;
	while (std::cin.fail()) {
		std::cout << "Enter new value" << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> input;
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return input;
}

void Greeting(void);
bool RightMenuChoice(Menu choice);
bool RightInputChoice(InputType choice);
Menu AskTests(void);
Menu AskRepeat(void);
InputType AskInput(void);
Menu AskSaveInput(void);
Menu AskSaveResult(void);
Menu AskRewriteFile(std::string path);
Menu AskSaveResult(void);
void MainFunction(void);
