# CPP_python_TEST
## Задание 1
В этом задании выводятся целые и дробные числа 

Код Python:
```
def zad11(a):
    i = int(a)
    return i
```

Код С++:
```
long zad11(long aa,PyObject *dict)
{
PyObject *python_class, *argums, *object;
python_class = PyDict_GetItemString(dict, "zad11");
PyObject *a;
a = PyLong_FromLong(aa);
argums = PyTuple_Pack(1,a);
object = PyObject_CallObject(python_class, argums);
Py_DECREF(python_class);
long o=PyLong_AsLong(object);
return o;
}
double zad12(double aa,PyObject *dict)
{
PyObject *python_class, *argums, *object;
python_class = PyDict_GetItemString(dict, "zad12");
PyObject *a;
a = PyFloat_FromDouble(aa);
argums = PyTuple_Pack(1,a);
object = PyObject_CallObject(python_class, argums);
Py_DECREF(python_class);
double o=PyFloat_AsDouble(object);
return o;
}
```

![Image1](https://cloud.paov.ru/index.php/s/cmowXkf7sTxY9CC/preview)
