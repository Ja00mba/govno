#include "Cl_4.h"

#include "Base.h"

Cl_4::Cl_4(Base* p, std::string n) : Base(p, n) {};

void Cl_4::signal_f(std::string& cmd) {
	cmd += " (class: 5)";
	Base::signal_f(cmd);
}

void Cl_4::handler_f(std::string cmd) {
	Base::handler_f(cmd);
}