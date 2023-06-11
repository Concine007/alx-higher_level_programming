#include <Python.h>

/**
 * print_python_list_info - Pri nts  b as ic i n fo  abo u t P yth onli s
 * @p: A Py Ob je ct  li st.
 */
void print_python_list_info(PyObject *p)
{
	int s, a, x;
	PyObject *obj;

	s = Py_SIZE(p);
	a = ((PyListObject *)p)->allocated;

	printf("[*] Size of the Python List = %d\n", s);
	printf("[*] Allocated = %d\n", a);

	for (x = 0; x < s; x++)
	{
		printf("Element %d: ", x);

		obj = PyList_GetItem(p, x);
		printf("%s\n", Py_TYPE(obj)->tp_name);
	}
}
