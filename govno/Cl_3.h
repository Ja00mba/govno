#ifndef __CL_3__H
#define __CL_3__H

#include <string>
#include <vector>
#include <iostream>

#include "Base.h"

class Cl_3 : public Base {
public:
	Cl_3(Base* p = nullptr, std::string n = "");
	virtual void signal_f(std::string&);
	virtual void handler_f(std::string);
};
#endif