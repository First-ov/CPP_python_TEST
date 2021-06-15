#include <Python.h>
#include <iostream>
#include <time.h>
#include <datetime.h>
struct point{
    long x;
    long y;
    long z;
};
point * get_point(long x,long y,long z)
{
point *p = new point;
p->x=x;
p->y=y;
p->z=z;
return p;
}

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
double o=PyLong_AsLong(object);
return o;
}
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
point * zad4(point * p,PyObject *dict)
{
std::cout<<"x:"<<p->x<<"y:"<<p->y<<"z:"<<p->z;
PyObject *python_class, *argums, *object, *attr;
python_class = PyDict_GetItemString(dict, "point");
argums = PyTuple_Pack(3,
PyLong_FromLong(p->x),
PyLong_FromLong(p->y),
PyLong_FromLong(p->z)
);

object = PyObject_CallObject(python_class,argums);
point * pp=get_point(PyLong_AsLong(PyObject_GetAttrString(object, "x")),
PyLong_AsLong(PyObject_GetAttrString(object, "y")),
PyLong_AsLong(PyObject_GetAttrString(object, "z")));
return pp;
}
int main() {
setenv("PYTHONPATH", ".", 1);
Py_Initialize();
PyObject *my_module_name, *module, *dict;
my_module_name = PyUnicode_FromString((char*)"lib");
module = PyImport_Import(my_module_name);
dict = PyModule_GetDict(module);
int inp;
do {
std::cout<<"Enter number of problem or 0 to exit:\n";
std::cin>>inp;
if (inp==1)
{
std::cout<<"Enter 1 for integer, 2 for double or any other to exit:\n";
std::cin>>inp;
if (inp==1)
{
long aa;
std::cout<<"Enter iteger:\n";
std::cin>>aa;
std::cout<<'\n'<<zad11(aa,dict)<<'\n';

}
if (inp==2)
{
double aa;
std::cout<<"Enter double:\n";
std::cin>>aa;
std::cout<<'\n'<<zad12(aa,dict)<<'\n';
}
}
if (inp==2)
{
std::cout<<"Enter 1 for string, 2 for date or any other to exit:\n";
std::cin>>inp;
if (inp==1)
{
char aa[100];
std::cout<<"Enter string:\n";
std::cin>>aa;
std::cout<<'\n'<<zad21(aa, dict)<<'\n';
}
if (inp==2)
{
char aa[100];
std::cout<<"Enter date in %m/%d/%YT%H:%M:%S format:\n";
std::cin>>aa;
time_t t;
t=zad22(aa, dict);
char mbstr[100];
strftime(mbstr, sizeof(mbstr), "%D %R", localtime(&t));
std::cout<<mbstr<<'\n';}}
if (inp==3)
{
const int x=3;
const int y=3;
long** X;
X = new long*[y];
for(int i=0;i<y;i++)
{X[i]=new long[x];}
int aa;
for(int i=0;i<y;i++){
for(int j=0;j<x;j++)
{
std::cout<<"Enter integer:\n";
std::cin>>aa;
X[i][j]=aa;

}}
long** Y=zad3(X,x,y,dict);
for(int i=0;i<y;i++){
for(int j=0;j<x;j++)
{std::cout<<Y[i][j]<<' ';}
std::cout<<'\n';
}
}
if (inp==4)
{
long x,y,z;
std::cout<<"Enter x y z:\n";
std::cin>>x>>y>>z;
point * p=get_point(x,y,z);
point * pp=zad4(p,dict);
std::cout<<"x:"<<pp->x<<"y:"<<pp->y<<"z:"<<pp->z<<'\n';
}
}while (inp!=0);
Py_Finalize();
return 0;
}
