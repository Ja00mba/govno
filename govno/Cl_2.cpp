#include "Cl_2.h"

#include "Base.h"

Cl_2::Cl_2(Base* p, std::string n) : Base(p, n) {};

void Cl_2::signal_f(std::string& cmd) {
	cmd += " (class: 3)";
	Base::signal_f(cmd);
}

void Cl_2::handler_f(std::string cmd) {
	Base::handler_f(cmd);
}