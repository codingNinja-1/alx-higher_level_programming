#include <stdlib.h>
#include <stdio.h>
#include <Python.h>

/**
 * print_python_list_info - function that prints some basic
 * info about Python lists
 * @p: python list
 */
void print_python_list_info(PyObject *p)
{
    Py_ssize_t size, elem;
    PyObject *item;

    if (!PyList_Check(p))
    {
        fprintf(stderr, "Invalid Python List\n");
        return;
    }

    size = PyList_Size(p);
    printf("[*] Size of the Python List = %ld\n", size);
    printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

    for (elem = 0; elem < size; elem++)
    {
        item = PyList_GetItem(p, elem);
        printf("Element %ld: ", elem);
        printf("%s\n", Py_TYPE(item)->tp_name);
    }
}

int main(void)
{
    Py_Initialize();

    // Example usage:
    PyObject *my_list = PyList_New(5);

    PyList_SetItem(my_list, 0, PyLong_FromLong(1));
    PyList_SetItem(my_list, 1, PyFloat_FromDouble(3.14));
    PyList_SetItem(my_list, 2, PyUnicode_FromString("Hello"));
    PyList_SetItem(my_list, 3, PyBool_FromLong(0));
    PyList_SetItem(my_list, 4, Py_None);

    print_python_list_info(my_list);

    Py_DECREF(my_list);
    Py_Finalize();

    return 0;
}
