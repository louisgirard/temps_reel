#ifndef __LOGGER_H__
#define __LOGGER_H__


#include <iostream>
#include <list>
#include <string>

class Logger
{
public:
	Logger(int enabled);
	~Logger();

	Logger operator<<(const char* val);
	Logger operator<<(char val);
	Logger operator<<(bool val);
	Logger operator<<(short val);
	Logger operator<<(unsigned short val);
	Logger operator<<(int val);
	Logger operator<<(unsigned int val);
	Logger operator<<(long val);
	Logger operator<<(unsigned long val);
	Logger operator<<(float val);
	Logger operator<<(double val);
	Logger operator<<(long double val);
	Logger operator<<(void* val);
	Logger operator<<(std::string val);
	Logger operator<<(std::streambuf* val);
	Logger operator<<(std::ostream& (*val)(std::ostream&));
	Logger operator<<(std::ios& (*val)(std::ios&));
	Logger operator<<(std::ios_base& (*val)(std::ios_base&));

	static Logger log();
	static Logger log(const char* tag);

private:
	static int mode;
	static std::list<std::string> createBlacklist();
	static std::list<std::string> createWhitelist();
	static std::list<std::string> blacklist;
	static std::list<std::string> whitelist;

	int enabled;
};

#endif