#include "stdafx.h"
#include "Terminal.h"
#include "iTerminal.h"

int main()
{
	iTerminal * t = new Terminal();

	t->run();

	delete t;
	//system("pause");


}
