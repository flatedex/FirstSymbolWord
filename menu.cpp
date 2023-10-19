#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <Windows.h>
#include "menu.h"
#include "tests.h"
#include "file.h"
#include "algorithm.h"


void Greeting() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	std::cout << "Zakirov Ilyas 404" << std::endl;
	std::cout << "Lab 1, variant #4" << std::endl;
	std::cout << "Defined text. Find first word that begins with provided symbol." << std::endl;
}

bool RightMenuChoice(Menu choice) {
	if ((choice == Menu::NO) || (choice == Menu::YES)) {
		return true;
	}
	else {
		std::cout << "Use presented choises!" << std::endl;
		return false;
	}
}

bool RightInputChoice(InputType choice) {
	if ((choice == InputType::KEYBOARD) || (choice == InputType::FILE)) {
		return true;
	}
	else {
		std::cout << "Use presented choises!" << std::endl;
		return false;
	}
}

Menu AskTests(void) {
	std::cout << "Run tests?" << std::endl;
	std::cout << "1 - Yes" << std::endl;
	std::cout << "2 - No" << std::endl;
	std::cout << "Your choice:" << std::endl;
	Menu decision = static_cast<Menu>(GetInput<int>());
	while (!RightMenuChoice(decision)) {
		decision = static_cast<Menu>(GetInput<int>());
	}
	return decision;
}
Menu AskRepeat(void) {
	std::cout << "Would you like to run program again?" << std::endl;
	std::cout << "1 - Yes" << std::endl;
	std::cout << "2 - No" << std::endl;
	std::cout << "Your choice:" << std::endl;
	Menu decision = static_cast<Menu>(GetInput<int>());
	while (!RightMenuChoice(decision)) {
		decision = static_cast<Menu>(GetInput<int>());
	}
	return decision;
}

InputType AskInput(void) {
	std::cout << "How would you like to enter text?" << std::endl;
	std::cout << "1 - From file" << std::endl;
	std::cout << "2 - Manually" << std::endl;
	std::cout << "Your choice:" << std::endl;
	InputType decision = static_cast<InputType>(GetInput<int>());
	while (!RightInputChoice(decision)) {
		decision = static_cast<InputType>(GetInput<int>());
	}
	return decision;
}

Menu AskSaveInput(void) {
	std::cout << "Save input to file?" << std::endl;
	std::cout << "1 - Yes" << std::endl;
	std::cout << "2 - No" << std::endl;
	std::cout << "Your choice:" << std::endl;
	Menu decision = static_cast<Menu>(GetInput<int>());
	while (!RightMenuChoice(decision)) {
		decision = static_cast<Menu>(GetInput<int>());
	}
	return decision;
}

Menu AskSaveResult(void) {
	std::cout << "Save result to file?" << std::endl;
	std::cout << "1 - Yes" << std::endl;
	std::cout << "2 - No" << std::endl;
	std::cout << "Your choice:" << std::endl;
	Menu decision = static_cast<Menu>(GetInput<int>());
	while (!RightMenuChoice(decision)) {
		decision = static_cast<Menu>(GetInput<int>());
	}
	return decision;
}


Menu AskRewriteFile(std::string path) {

	Menu decision = Menu::NO;

	std::cout << "File already exist!" << std::endl;
	std::cout << "1 - Create new" << std::endl;
	std::cout << "2 - Rewrite current" << std::endl;
	std::cout << "Your choice:" << std::endl;
	decision = static_cast<Menu>(GetInput<int>());
	while (!RightMenuChoice(decision)) {
		decision = static_cast<Menu>(GetInput<int>());
	}
	return decision;

}

void MainFunction(void) {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	auto wantTests = Menu::YES;
	auto wantContinue = Menu::YES;
	auto wantSave = Menu::YES;
	auto wantRewrite = Menu::YES;
	auto inputType = InputType::KEYBOARD;
	std::string text;
	std::string afterText;
	std::string result = "";
	char symbol = ' ';
	const int castSingleChar = 1;

	do {
		std::string filePath = "nothing";
		wantTests = AskTests();
		if (wantTests == Menu::YES) {
			Tests();
		}

		inputType = AskInput();

		if (inputType == InputType::FILE) {
			std::cout << "Text input" << std::endl;
			ReadFromFile(text, symbol);
			std::cout << "Source text:" << std::endl;
			std::cout << text << std::endl;
		}
		else {
			std::cout << "Enter text:" << std::endl;
			getline(std::cin, text);
			std::cout << "Enter symbol:" << std::endl;
			std::cin >> symbol;
		}

		result = FindWord(text, symbol);
		if (result != "") {
			std::cout << result + " is what you were finding for!" << std::endl;
		}
		else {
			std::string ans(castSingleChar, symbol);
			std::cout << "There is no such word that begins with " + ans << std::endl;
		}

		if (inputType != InputType::FILE) {
			wantSave = AskSaveInput();
			if (wantSave == Menu::YES) {
				std::cout << "Saving source text" << std::endl;
				WriteInFile(text, symbol);
			}
		}

		wantSave = AskSaveResult();
		if (wantSave == Menu::YES) {

			std::cout << "Enter file name:" << std::endl;
			filePath = GetInput<std::string>();
			FileWork outputSaveFile(filePath);
			while (!outputSaveFile.SaveFileNormal()) {
				std::cout << "Enter new file name" << std::endl;
				filePath = outputSaveFile.RewriteName();
			}
			wantRewrite = AskRewriteFile(filePath);
			if (wantRewrite == Menu::YES) {
				std::string newFilePath = filePath;
				FileWork newOutputSave(newFilePath);
				while (newFilePath == filePath) {
					std::cout << "Enter new file name" << std::endl;
					newFilePath = newOutputSave.RewriteName();
					while (!newOutputSave.SaveFileNormal()) {
						std::cout << "Enter new file name" << std::endl;
						newFilePath = newOutputSave.RewriteName();
					}
				}
				FileWork file(newFilePath);
				file.Output(text, result);
			}
			else {
				while (outputSaveFile.FileReadOnly()) {
					std::cout << "Enter new file name" << std::endl;
					filePath = outputSaveFile.RewriteName();
				}
				FileWork file(filePath);
				file.Output(text, result);
			}


		}
		wantContinue = AskRepeat();
	} while (wantContinue == Menu::YES);
}