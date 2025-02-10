#include <iostream>


using namespace std;



// pass object to function by pass by value
class Obj {
public:
    int num;
};
void func (Obj obj) {
    cout << obj.num << endl;
}
void p1() {
    Obj obj;
    obj.num = 70;
    func(obj);
}


// pass object to function by pass by address
void func2 (Obj* obj) {
    cout << obj->num << endl;
}
void p2() {
    Obj obj;
    obj.num = 80;
    func(obj);
}


// use friend function to accesss private data using non member function
class Obj3 {
    int num = 100;
    friend void func3(Obj3& obj);
};
void func3 (Obj3& obj) {
    cout << obj.num << endl;
}
void p3() {
    Obj3 obj;
    func3(obj);
}


// declare friend function in classes. Calculate sum of ints of both classes using friend function
class ObjY4;
class ObjX4 {
    int num = 500;
    friend void print_sum4(ObjX4& objX, ObjY4& objY);
};
class ObjY4 {
    int num = 200;
    friend void print_sum4(ObjX4& objX, ObjY4& objY);
};

void print_sum4(ObjX4& objX, ObjY4& objY) {
    cout << objX.num + objY.num << endl;
}

void p4() {
    ObjX4 objX;
    ObjY4 objY;
    print_sum4(objX, objY);
}


// exchange value between two classes by using friend function
class ObjY5;
class ObjX5 {
    int num = 500;
    friend void exchange_val(ObjX5& objX, ObjY5& objY);
    friend void print_val(ObjX5& objX, ObjY5& objY);
};
class ObjY5 {
    int num = 200;
    friend void exchange_val(ObjX5& objX, ObjY5& objY);
    friend void print_val(ObjX5& objX, ObjY5& objY);
};

void exchange_val(ObjX5& objX, ObjY5& objY) {
    swap(objX.num, objY.num);
}
void print_val(ObjX5& objX, ObjY5& objY) {
    cout << "objX.num = " << objX.num << endl;
    cout << "objY.num = " << objY.num << endl;
}

void p5() {
    ObjX5 objX;
    ObjY5 objY;
    print_val(objX, objY);
    exchange_val(objX, objY);
    print_val(objX, objY);
}

// declare friend classes and access private data
class Y6;
class X6 {
    int num = 100;
    friend class Y6;
public:
    void accessY (Y6& y);
};

class Y6 {
    int num = 200;
    friend class X6;
public:
    void accessX (X6& x) {
        cout << x.num << endl;
    }
};

void X6::accessY(Y6& y) {
    cout << y.num << endl;
}

void p6() {
    X6 x;
    Y6 y;
    x.accessY(y);
    y.accessX(x);
}



// declare 3 classes. declare integer arrays as data members in each class 
// perform addition of two data member arrays into array of third class using friend functions
class Z7;
class X7 {
    int arr[5] = {1,2,5,7,2};
    friend class Z7;
};
class Y7 {
    int arr[5] = {6,0,8,-3,2};
    friend class Z7;
};
class Z7 {
    int arr[5];
public:
    void add(X7& x, Y7& y) {
        for (int i = 0; i < 5; i++) {
            arr[i] = x.arr[i] + y.arr[i];
        }
    }
    void print_arr() {
        cout << "Z.arr = ";
        for (int i = 0; i < 5; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

void p7() {
    X7 x;
    Y7 y;
    Z7 z;
    z.add(x, y);
    z.print_arr();
}



int main() {
    p1();
    p2();
    p3();
    p4();
    p5();
    p6();
    p7();
    return 0;
}