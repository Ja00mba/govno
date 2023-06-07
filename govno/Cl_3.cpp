#include "Cl_3.h"

#include "Base.h"

Cl_3::Cl_3(Base* p, std::string n) : Base(p, n) {};

void Cl_3::signal_f(std::string& cmd) {
	cmd += " (class: 4)";
	Base::signal_f(cmd);
}

void Cl_3::handler_f(std::string cmd) {
	Base::handler_f(cmd);
}