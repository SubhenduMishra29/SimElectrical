#include <stdio.h>
//#include <conio.h>
#include <Python.h>

int main()
{
	PyObject* pInt;

	Py_Initialize();

	PyRun_SimpleString("import pandapower as pp");
	PyRun_SimpleString("net = pp.create_empty_network(sn_mva = 100 )");
	PyRun_SimpleString("print(net)");
	Py_Finalize();

	printf("\nPress any key to exit...\n");
	//if(!_getch()) _getch();
	return 0;
}
