#include <string>
#include <iostream>
#include <vector>

#include "Application.h"
#include "Base.h"
#include "Child_1.h"
#include "Cl_2.h"
#include "Cl_3.h"
#include "Cl_4.h"
#include "Cl_5.h"

Application::Application() : Base(nullptr, "") {};

void Application::create() {
	std::string root_name(""), child_name("");
	std::cin >> root_name;

	int class_number = 0;
	this->setName(root_name);

	setState(1);

	while (true) {
		std::cin >> root_name;
		if (root_name == "endtree") {
			break;
		}

		std::cin >> child_name >> class_number;
		auto p = coord(root_name);
		Base* obj;

		switch (class_number) {
		case 2:
			obj = new Child_1(p, child_name);
			break;
		case 3:
			obj = new Cl_2(p, child_name);
			break;
		case 4:
			obj = new Cl_3(p, child_name);
			break;
		case 5:
				obj = new Cl_4(p, child_name);
			break;
		case 6:
			obj = new Cl_5(p, child_name);
			break;
		default:
			obj = nullptr;
		}
		if (obj)
		{
			obj->setState(1);

		}
	}
	print();
	while (true) {
		std::cin >> root_name;
		if (root_name == "end_of_connections")
			break;

		std::cin >> child_name;

		auto found = coord(root_name);
		auto target = coord(child_name);

		if (!found || !target)
			continue;
		found->connect(
			SIGNAL_D(Base::signal_f),
			target,
			HANDLER_D(Base::handler_f)
		);
	}
}

void Application::print() {
	std::cout << "Object tree\n";
	printTree(false);
}

int Application::execApp() {
	std::string str(""), strl("");
	int state;
	while (true) {
		std::cin >> str;
		if (str == "END") {
			break;
		}
		std::cin >> strl;
		auto found = coord(strl);
		if (!found) {
			std::cout << "\nObject " << strl << " not found";
			continue;
		}

		Base* target;
		if (str == "SET_CONNECT" || str == "DELETE_CONNECT") {
			std::cin >> strl;
			target = coord(strl);
			if (!target) {
				std::cout << "\nHandler object " << path << " not found";
				continue;
			}
		}
		if (str == "EMIT") {
			std::getline(std::cin, strl);
			found->emit(SIGNAL_D(Base::signal_f), path);
		}
		else if (str == "SET_CONNECT") {
			found->connect(
				SIGNAL_D(Base::signal_f),
				target,
				HANDLER_D(Base::handler_f)
			);
		}
		else if (str == "DELETE_CONNECT") {
			found->disconnect(
				SIGNAL_D(Base::signal_f),
				target,
				HANDLER_D(Base::handler_f)
			);
		}
		else if (str == "SET_CONDITION") {
			std::cin >> state;
			found->setState(state);
		}
	}
	return 0;
}