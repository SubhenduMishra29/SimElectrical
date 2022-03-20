#include <stdio.h>
#include <Python.h>
#include <pyhelper.hpp>

int main()
{
	CPyInstance hInstance;

	CPyObject pName = PyUnicode_FromString("pyemb3");
	CPyObject pModule = PyImport_Import(pName);

	if(pModule)
	{
		CPyObject pFunc = PyObject_GetAttrString(pModule, "getInteger");
		if(pFunc && PyCallable_Check(pFunc))
		{
			CPyObject pValue = PyObject_CallObject(pFunc, NULL);

			printf("C: getInteger() = %ld\n", PyLong_AsLong(pValue));
		}
		else
		{
			printf("ERROR: function getInteger()\n");
		}

	}
	else
	{
		printf("ERROR: Module not imported\n");
	}

	return 0;
}
