#ifndef __CL_4__H
#define __CL_4__H

#include <string>
#include <vector>
#include <iostream>

#include "Base.h"

class Cl_4 : public Base {
public:
	Cl_4(Base* p = nullptr, std::string n = "");
	virtual void signal_f(std::string&);
	virtual void handler_f(std::string);
};
#endif