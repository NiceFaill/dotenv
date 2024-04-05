#pragma once
#include "pch.h"
__declspec(dllexport) class dotenv
{
public:
	__declspec(dllexport) static void load_dotenv(const std::string &&string);
	__declspec(dllexport) static std::string getenv(const std::string &&string);
private:
	static std::map<std::string, std::string> envMap;
};