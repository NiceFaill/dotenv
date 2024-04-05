#pragma once
#include "pch.h"

class dotenv
{
public:
	static void load_dotenv(const std::string &&string);
	static std::string getenv(const std::string &&string);
private:
	static std::map<std::string, std::string> envMap;
};