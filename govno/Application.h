#ifndef __APPLICATION__H
#define __APPLICATION__H

#include "Base.h"
#include "Child_1.h"

#include <string>
#include <vector>

class Application : public Base {
public:
	Application();
	void create();
	void print();
	int execApp();
};
#endif