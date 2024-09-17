#include "denjipch.h"
#include "Log.h"

DENJI_API Denji::Log* Denji::Log::_globalLog;

Denji::Log::Log(std::string name)
{
	_name = name;
	_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

Denji::Log::Log()
{
	_name = "Generic Log";
	_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
}

Denji::Log::~Log()
{
}

void Denji::Log::Init()
{
	if (!_globalLog)
		_globalLog = new Log("Static Denji Log");
}

void Denji::Log::Print(std::string text, const char* file, int line)
{
	SetConsoleTextAttribute(_hConsole, (int)_selectedColor);
	std::cout << _name << *" (" << file << ", " << line << ")" << ": " << text << std::endl;
}

void Denji::Log::Print(std::string text, const char* file, int line, ConsoleColor color)
{
	SetConsoleTextAttribute(_hConsole, (int)color);
	std::cout << _name << *" (" << file << ", " << line << ")" << ": " << text << std::endl;
}

void Denji::Log::Print_Log(std::string text, const char* file, int line)
{
	SetConsoleTextAttribute(_hConsole, (int)ConsoleColor::GREEN);
	std::cout << _name << *" (" << file << ", " << line << ")" << ": " << text << std::endl;
}

void Denji::Log::Print_Info(std::string text, const char* file, int line)
{
	SetConsoleTextAttribute(_hConsole, (int)ConsoleColor::CYAN);
	std::cout << _name << *" (" << file << ", " << line << ")" << ": " << text << std::endl;
}

void Denji::Log::Print_Error(std::string text, const char* file, int line)
{
	SetConsoleTextAttribute(_hConsole, (int)ConsoleColor::RED);
	std::cout << _name << *" (" << file << ", " << line << ")" << ": " << text << std::endl;
}
