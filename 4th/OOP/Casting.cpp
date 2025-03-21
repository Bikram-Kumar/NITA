#include <iostream>
#include <string>
using namespace std;

// to define constructor with no args and with float arg. explain how compiler invokes constructor
// depending on data types 
class MyClass {
    float num;
public:
    MyClass() {
        cout << "Constructor with no args called\n";
    }
    MyClass(float num) : num(num) {
        cout << "Constructor with float arg called\n";
        cout << "Arg = " << num << endl;
    }
};

void p1() {
    MyClass obj;      // no arg
    MyClass objF(6.7);  // float arg
}




// to convert class type data to basic type data
class MyData {
    int num;
    string str;
public:
    MyData (int num, string str) : num(num), str(str) {}
    operator string() {
        return ("{ num: " + to_string(num) + ", " + " str: \"" + str + "\" }");
    }
};
void p2() {
    MyData myData(80, "Oranges");
    string myDataBasic = myData;
    cout << myDataBasic << endl;
}


// to convert int to date and vice versa using conversion in destination class
class Date {
public:
    int seconds;
    string date;
    Date& operator=(int seconds) {
        this->seconds = seconds;
        time_t t = seconds;
        date = asctime(localtime(&t));
        return *this;
    }
    operator int() {
        return seconds;
    }
    
};

void p3() {
    Date date;
    date = time(nullptr);
    cout << "Date: " << date.date;
    int iDate= date;
    cout << "int: " << iDate << endl;
}


// to derive a class publicly from base class. declare the base class with its member under public section
class Base {
public:
    int data = 890;
};

class Child : public Base{

};

void p4() {
    Child child;
    cout << child.data << endl;
    child.data = 50;
    cout << child.data << endl;
}



int main() {
    p1();
    p2();
    p3();
    p4();
    return 0;
}