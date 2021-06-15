# CPP_python_TEST
## Задание 1
В этом задании выводятся целые и дробные числа 

Код Python:
```
def zad11(a):
    i = int(a)
    return i
    
    
def zad12(a):
    i = float(a)
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

## Задание 2
В этом задании выводятся строки и даты

Код Python:
```
def zad21(a):
    s = str(a)
    return s


def zad22(a):
    s = str(a)
    ss=datetime.datetime.strptime(s, "%m/%d/%YT%H:%M:%S")
    return ss
```

Код С++:
```
char* zad21(char* aa,PyObject *dict)
{
PyObject *python_class, *argums, *object;
python_class = PyDict_GetItemString(dict, "zad21");
PyObject *a;
a = PyUnicode_FromString(aa);
argums = PyTuple_Pack(1,a);
object = PyObject_CallObject(python_class, argums);
Py_DECREF(python_class);
PyObject * ascii_mystring=PyUnicode_AsASCIIString(object);
char * o=PyBytes_AsString(ascii_mystring);
Py_DECREF(ascii_mystring);
return o;
}
time_t zad22(char* aa,PyObject *dict)
{
PyObject *python_class, *argums, *object;
python_class = PyDict_GetItemString(dict, "zad22");
PyObject *a;
a = PyUnicode_FromString(aa);
argums = PyTuple_Pack(1,a);
object = PyObject_CallObject(python_class, argums);
tm tm;
tm.tm_year = PyDateTime_GET_YEAR(object)-1900;
tm.tm_mon = PyDateTime_GET_MONTH(object)-1;
tm.tm_mday = PyDateTime_GET_DAY(object);
tm.tm_hour = PyDateTime_DATE_GET_HOUR(object);
tm.tm_min = PyDateTime_DATE_GET_MINUTE(object);
tm.tm_isdst = 0;
time_t t = mktime(&tm);
return t;}
```
![Image2](https://cloud.paov.ru/index.php/s/BRHnjT2RsYojtdk/preview)

## Задание 3
В этом задании выводится массив 3*3

Код Python:
```
def zad3(a):
    return a;
```

Код С++:
```
long** zad3(long** aa,int x,int y,PyObject *dict)
{
PyObject *python_class, *argums, *object;
python_class = PyDict_GetItemString(dict, "zad3");
PyObject *a;
a=PyList_New(0);
for(int i=0;i<y;i++)
{
PyObject *b;
b=PyList_New(0);
for(int j=0;j<x;j++)
{
PyList_Append(b,PyLong_FromLong(aa[i][j]));
}
PyList_Append(a,b);
}
argums = PyTuple_Pack(1,a);
object = PyObject_CallObject(python_class, argums);

long **bb = new long*[y];
for(int i=0;i<y;i++)
{bb[i]=new long[x];}
for(int i=0;i<y;i++)
for(int j=0;j<x;j++)
{
bb[i][j]=PyLong_AsLong(PyList_GetItem(PyList_GetItem(object,i),j));;
}
return bb;
}
```

![Image3](https://cloud.paov.ru/index.php/s/cj6yYgAJ6MykKzP/preview)

