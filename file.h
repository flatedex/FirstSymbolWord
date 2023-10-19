#pragma once

#include <fstream>
#include <filesystem>
#include "menu.h"

class FileWork {
	std::string m_path;
public:
	FileWork(std::string path);
	bool NameForbidden(void) ;
	std::string RewriteName(void);
	bool FileExist(void) ;
	bool SaveFileNormal(void) ;
	bool FileReadOnly() ;
	void Output(std::string& text, std::string result);
	void SaveData(std::string& afterText, char symbol);
	bool Input(std::string& usingText, char& symbol);
};


void WriteInFile(std::string& afterText, char symbol);

void ReadFromFile(std::string& usingText, char& symbol);