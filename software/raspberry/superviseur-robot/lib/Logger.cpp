#include "Logger.h"

#define ALL 0
#define BLACKLIST 1
#define WHITELIST 2
#define NONE 3

int Logger::mode = ALL;

std::list<std::string> Logger::createBlacklist() {
	std::list<std::string> list;
	//list.push_back("default");
	list.push_back("battery");
	return list;
}

std::list<std::string> Logger::createWhitelist() {
	std::list<std::string> list;
	//list.push_back("default");
	list.push_back("sendToRobot");
	return list;
}

Logger::Logger(int enabled)
{
	this->enabled = enabled;
}


Logger::~Logger()
{
}

Logger Logger::operator<<(const char* val) {
	if (enabled) {
		std::cout << val;
	}
	return *this;
}

Logger Logger::operator<<(char val) {
	if (enabled) {
		std::cout << val;
	}
	return *this;
}

Logger Logger::operator<<(bool val) {
	if (enabled) {
		std::cout << val;
	}
	return *this;
}

Logger Logger::operator<<(short val) {
	if (enabled) {
		std::cout << val;
	}
	return *this;
}

Logger Logger::operator<<(unsigned short val) {
	if (enabled) {
		std::cout << val;
	}
	return *this;
}

Logger Logger::operator<<(int val) {
	if (enabled) {
		std::cout << val;
	}
	return *this;
}

Logger Logger::operator<<(unsigned int val) {
	if (enabled) {
		std::cout << val;
	}
	return *this;
}

Logger Logger::operator<<(long val) {
	if (enabled) {
		std::cout << val;
	}
	return *this;
}

Logger Logger::operator<<(unsigned long val) {
	if (enabled) {
		std::cout << val;
	}
	return *this;
}

Logger Logger::operator<<(float val) {
	if (enabled) {
		std::cout << val;
	}
	return *this;
}

Logger Logger::operator<<(double val) {
	if (enabled) {
		std::cout << val;
	}
	return *this;
}

Logger Logger::operator<<(long double val) {
	if (enabled) {
		std::cout << val;
	}
	return *this;
}

Logger Logger::operator<<(void* val) {
	if (enabled) {
		std::cout << val;
	}
	return *this;
}

Logger Logger::operator<<(std::string val) {
	if (enabled) {
		std::cout << val;
	}
	return *this;
}

Logger Logger::operator<<(std::streambuf* val) {
	if (enabled) {
		std::cout << val;
	}
	return *this;
}
Logger Logger::operator<<(std::ostream& (*val)(std::ostream&)) {
	if (enabled) {
		std::cout << val;
	}
	return *this;
}
Logger Logger::operator<<(std::ios& (*val)(std::ios&)) {
	if (enabled) {
		std::cout << val;
	}
	return *this;
}
Logger Logger::operator<<(std::ios_base& (*val)(std::ios_base&)) {
	if (enabled) {
		std::cout << val;
	}
	return *this;
}

 Logger Logger::log() {
	 return Logger::log("default");
 }

 Logger Logger::log(const char* tag) {
	std::string strTag{tag};
	int enabled = (Logger::mode == ALL || Logger::mode == BLACKLIST) ? 1 : 0;
	std::list<std::string>::iterator it;
	if (Logger::mode == BLACKLIST) {
		for (it = Logger::blacklist.begin(); it != Logger::blacklist.end(); ++it){
			if (strTag == *it) {
				enabled = 0;
				break;
			}
		}
	}
	if (Logger::mode == WHITELIST) {
		for (it = Logger::whitelist.begin(); it != Logger::whitelist.end(); ++it){
			if (strTag == *it) {
				enabled = 1;
				break;
			}
		}
	}	
	if (enabled) {
		std::cout << "[" << tag << "] ";
	}
	Logger logger(enabled);
	return logger;
 }

 std::list<std::string> Logger::blacklist = createBlacklist();
 std::list<std::string> Logger::whitelist = createWhitelist();