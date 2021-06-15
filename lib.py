import datetime

def zad11(a):
    i = int(a)
    return i


def zad12(a):
    i = float(a)
    return i


def zad21(a):
    s = str(a)
    return s


def zad22(a):
    s = str(a)
    ss=datetime.datetime.strptime(s, "%m/%d/%YT%H:%M:%S")
    return ss


def zad3(a):
    return a;


class point():
    def __init__(self, x, y,z):
        self.x = x
        self.y = y
        self.z = z
def zad4(a):
    return a