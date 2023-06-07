#ifndef __CL_5__H
#define __CL_5__H

#include <string>
#include <vector>
#include <iostream>

#include "Base.h"

class Cl_5 : public Base {
public:
	Cl_5(Base* p = nullptr, std::string n = "");
	virtual void signal_f(std::string&);
	virtual void handler_f(std::string);
};
#endif