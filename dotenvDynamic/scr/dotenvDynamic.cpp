#include "pch.h"
#include "dotenv.h"
__declspec(dllexport) void dotenv::load_dotenv(const std::string &&string)
{
	std::ifstream file(string);
	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			size_t delimiterPos = line.find('=');
			if (delimiterPos != std::string::npos)
			{
				std::string key = line.substr(0, delimiterPos);
				std::string value = line.substr(delimiterPos + 1);
				envMap[key] = value;
			}
		}
		file.close();
	}
	else
	{
		throw std::exception("ENV file is not opened.");
		exit(0);
	}
}

__declspec(dllexport) std::string dotenv::getenv(const std::string &&string)
{
	auto it = envMap.find(string);
	if (it != envMap.end())
	{
		return it->second;
	}
	else
	{
		throw std::exception("Key is not found.");
	}
}
std::map<std::string, std::string> dotenv::envMap;