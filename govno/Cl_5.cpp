#include "Cl_5.h"

#include "Base.h"

Cl_5::Cl_5(Base* p, std::string n) : Base(p, n) {};

void Cl_5::signal_f(std::string& cmd) {
	cmd += " (class: 6)";
	Base::signal_f(cmd);
}
void Cl_5::handler_f(std::string cmd) {
	Base::handler_f(cmd);
}