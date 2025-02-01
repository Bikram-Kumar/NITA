#include <iostream>
#include <iomanip>
#include <cmath>

#if defined(__INTELLISENSE__)
    #include <corecrt_math_defines.h>
#endif

using namespace std;



// name, address as char array, age as int, salary as float and contains inline functions to
// set the values and display it
template<class T>
inline void set_value(T& var, string label) {
    cout<< "Enter " + label + ": ";
    cin >> var;
}

template<class T>
inline void print_val(T& var, string label) {
    cout << label << " = " << var << endl;
}



void p1() {
    char name[64];
    char address[64];
    int age;
    float salary;
    set_value(name, "Name");
    set_value(address, "Address");
    set_value(age, "Age");
    set_value(salary, "Salary");
    print_val(name, "Name");
    print_val(address, "Address");
    print_val(age, "Age");
    print_val(salary, "Salary");
}



// using function overloading write function for caluculating the area of a triangle, circle and rectangle

double area(double& a, double& b, double& c) {
    double s = (a+b+c)/2;
    return sqrt(s * (s-a) * (s-b) * (s-c));
}
double area(double& b, double& h) {
    return (b * h);
}
double area(double& r) {
    return (M_PI * r * r);
}

void p2() {
    double a, b, c;
    cout << "Enter sides of triangle: ";
    cin >> a >> b >> c;
    cout << fixed << setprecision(2);
    cout << "Area of triangle = " << area(a,b,c) << endl;
    cout << "Enter sides of rectangle: ";
    cin >> a >> b;
    cout << "Area of rectangle = " << area(a,b) << endl;
    cout << "Enter radius of circle: ";
    cin >> a;
    cout << "Area of circle = " << area(a) << endl;
}



// write a function power to raise a number m to power to n. the function takes a double value of m and int vallue for n
// use default for n to make the function to calculate square when these arguments is omitted
double power(double m, int n = 2) {
    double k = 1.0;
    while (n--) k *= m;
    return k;
}

void p3() {
    double m;
    int n;
    cout << "Enter base and power: ";
    cin >> m >> n;
    cout << fixed << setprecision(2);
    cout << m << "^" << n << " = " << power(m, n) << endl;
}

int main () {
    p1();
    p2();
    p3();
    return 0;
}