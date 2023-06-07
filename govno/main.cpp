#include <stdlib.h>
#include <stdio.h>
#include "Application.h"
int main()
{
	Application app{};
	app.create();
	return app.execApp();
}