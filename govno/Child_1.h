#ifndef __CHILD_1__H
#define __CHILD_1__H

#include <string>
#include <vector>
#include <iostream>

#include "Base.h"

class Child_1 : public Base {
public:
	Child_1(Base* p = nullptr, std::string n = "");
	virtual void signal_f(std::string&);
	virtual void handler_f(std::string);
};
#endif