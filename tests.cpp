#include <iostream>
#include <string>
#include "algorithm.h"

bool Test1() {
	const std::string expected = "suscipit";
	const std::string text = "Integer eleifend suscipit eleifend. Class aptent taciti.";
	const char symbol = 's';
	std::string ans = FindWord(text, symbol);
	if (ans != expected) {
		std::cout << "Text #1 failed" << std::endl;
		std::cout << "Expected result: " << expected << std::endl;
		std::cout << "But output was: " << ans << std::endl;
		return false;
	}
	return true;
}
bool Test2() {
	const std::string expected = "";
	const std::string text = "many-symbols-kebab-case";
	const char symbol = '{';
	std::string ans = FindWord(text, symbol);
	if (ans != expected) {
		std::cout << "Text #2 failed" << std::endl;
		std::cout << "Expected result: " << expected << std::endl;
		std::cout << "But output was: " << ans << std::endl;
		return false;
	}
	return true;
}
bool Test3() {
	const std::string expected = "234";
	const std::string text = "twerq 234 2khjjkh";
	const char symbol = '2';
	std::string ans = FindWord(text, symbol);
	if (ans != expected) {
		std::cout << "Text #3 failed" << std::endl;
		std::cout << "Expected result: " << expected << std::endl;
		std::cout << "But output was: " << ans << std::endl;
		return false;
	}
	return true;
}
bool Test4() {
	const std::string expected = "provides";
	const std::string text = "Golang provides Goroutines as paralell running tasks";
	const char symbol = 'p';
	std::string ans = FindWord(text, symbol);
	if (ans != expected) {
		std::cout << "Text #4 failed" << std::endl;
		std::cout << "Expected result: " << expected << std::endl;
		std::cout << "But output was: " << ans << std::endl;
		return false;
	}
	return true;
}
bool Test5() {
	const std::string expected = "a";
	const std::string text = "not a single test failing today";
	const char symbol = 'a';
	std::string ans = FindWord(text, symbol);
	if (ans != expected) {
		std::cout << "Text #5 failed" << std::endl;
		std::cout << "Expected result: " << expected << std::endl;
		std::cout << "But output was: " << ans << std::endl;
		return false;
	}
	return true;
}


void Tests() {
	int trueTests = 0;
	if (Test1()) trueTests++;
	if (Test2()) trueTests++;
	if (Test3()) trueTests++;
	if (Test4()) trueTests++;
	if (Test5()) trueTests++;
	if (trueTests == 5) {
		std::cout << "Tests ran successfully" << std::endl;
	}
}