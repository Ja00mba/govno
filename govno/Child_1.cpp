#include "Child_1.h"

#include "Base.h"

Child_1::Child_1(Base* p, std::string n) : Base(p, n) {};

void Child_1::signal_f(std::string& cmd) {
	cmd += " (class: 2)";
	Base::signal_f(cmd);
}

void Child_1::handler_f(std::string cmd) {
	Base::handler_f(cmd);
}