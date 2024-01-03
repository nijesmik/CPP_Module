#ifndef CPP_MODULE_HARL_HPP
#define CPP_MODULE_HARL_HPP

#include "iostream"

class Harl {
public:
	void complain(std::string level);

private:
	void debug(void);

	void info(void);

	void warning(void);

	void error(void);
};

#endif
