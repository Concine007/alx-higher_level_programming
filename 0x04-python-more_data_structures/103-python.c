#include <stdio.h>
#include <Python.h>

/**
 * print_python_bytes - Pr in ts   b y t e s   i nf o r  m a t i on
 * @p: Py th on  Ob je c t
 * Return: n o  re t u  rn
 */
void print_python_bytes(PyObject *p)
{
char *string;
long int s, x, l;

printf("[.] bytes object info\n");
if (!PyBytes_Check(p))
{
printf("  [ERROR] Invalid Bytes Object\n");
return;
}
s = ((PyVarObject *)(p))->ob_size;
string = ((PyBytesObject *)p)->ob_sval;
printf("  size: %ld\n", s);
printf("  trying string: %s\n", string);
if (s >= 10)
l = 10;
else
l = s + 1;
printf("  first %ld bytes:", l);
for (x = 0; x < l; x++)
if (string[x] >= 0)
printf(" %02x", string[x]);
else
printf(" %02x", 256 + string[x]);
printf("\n");
}

/**
 * print_python_list - P r in t s  l  is t   i n f o r m a t i on
 * @p: Py th o n   O b je ct
 * Return: n o r et u r n
 */
void print_python_list(PyObject *p)
{
long int s, x;
PyListObject *l;
PyObject *obj;

s = ((PyVarObject *)(p))->ob_size;
l = (PyListObject *)p;
printf("[*] Python list info\n");
printf("[*] Size of the Python List = %ld\n", s);
printf("[*] Allocated = %ld\n", l->allocated);
for (x = 0; x < s; x++)
{
obj = ((PyListObject *)p)->ob_item[x];
printf("Element %ld: %s\n", x, ((obj)->ob_type)->tp_name);
if (PyBytes_Check(obj))
print_python_bytes(obj);
}
