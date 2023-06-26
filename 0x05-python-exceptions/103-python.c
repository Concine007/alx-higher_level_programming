/*
 * File: 103-python.c
 * Auth: Natnael Abebe
 */

#include <Python.h>

void print_python_list(PyObject *p);
void print_python_bytes(PyObject *p);
void print_python_float(PyObject *p);

/**
 * print_python_list - P r i n t s  b a si c in fo ab o u t Py t h on lists.
 * @p: A P yO b je c t  l i s  t   ob j e c t.
 */
void print_python_list(PyObject *p)
{
	Py_ssize_t size, alloc, x;
	const char *type;
	PyListObject *list = (PyListObject *)p;
	PyVarObject *var = (PyVarObject *)p;

	size = var->ob_size;
	alloc = list->allocated;

	fflush(stdout);

	printf("[*] Python list info\n");
	if (strcmp(p->ob_type->tp_name, "list") != 0)
	{
		printf("  [ERROR] Invalid List Object\n");
		return;
	}

	printf("[*] Size of the Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", alloc);

	for (x = 0; x < size; x++)
	{
		type = list->ob_item[x]->ob_type->tp_name;
		printf("Element %ld: %s\n", x, type);
		if (strcmp(type, "bytes") == 0)
			print_python_bytes(list->ob_item[x]);
		else if (strcmp(type, "float") == 0)
			print_python_float(list->ob_item[x]);
	}
}

/**
 * print_python_bytes - Pr i n ts ba s ic in f o abo u t P yt h o n byte
 * @p: A P y O b j e  c t  by t e  o b  j e c t.
 */
void print_python_bytes(PyObject *p)
{
	Py_ssize_t size, x;
	PyBytesObject *bytes = (PyBytesObject *)p;

	fflush(stdout);

	printf("[.] bytes object info\n");
	if (strcmp(p->ob_type->tp_name, "bytes") != 0)
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	printf("  size: %ld\n", ((PyVarObject *)p)->ob_size);
	printf("  trying string: %s\n", bytes->ob_sval);

	if (((PyVarObject *)p)->ob_size >= 10)
		size = 10;
	else
		size = ((PyVarObject *)p)->ob_size + 1;

	printf("  first %ld bytes: ", size);
	for (x = 0; x < size; x++)
	{
		printf("%02hhx", bytes->ob_sval[i]);
		if (x == (size - 1))
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_python_float - Pr in ts b as ic in fo abo ut Py th on fl oa t ob je c
 * @p: A Py Ob je ct fl oa t ob je ct.
 */
void print_python_float(PyObject *p)
{
	char *buffer = NULL;

	PyFloatObject *float_obj = (PyFloatObject *)p;

	fflush(stdout);

	printf("[.] float object info\n");
	if (strcmp(p->ob_type->tp_name, "float") != 0)
	{
		printf("  [ERROR] Invalid Float Object\n");
		return;
	}

	buffer = PyOS_double_to_string(float_obj->ob_fval, 'r', 0,
			Py_DTSF_ADD_DOT_0, NULL);
	printf("  value: %s\n", buffer);
	PyMem_Free(buffer);
}
