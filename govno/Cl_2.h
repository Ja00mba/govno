#ifndef __CL_2__H
#define __CL_2__H

#include <string>
#include <vector>
#include <iostream>

#include "Base.h"

class Cl_2 : public Base {
public:
	Cl_2(Base* p = nullptr, std::string n = "");
	virtual void signal_f(std::string&);
	virtual void handler_f(std::string);
};
#endif