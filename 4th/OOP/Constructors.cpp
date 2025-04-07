#include <iostream>

using namespace std;

// to show sequence of execution of constructor and destructor in multiple inheritance
class X1_1 {
public:
    X1_1 () {
        cout << "X1 constructor called\n";
    }
    ~X1_1 () {
        cout << "X1 destructor called\n";
    }
    
};
class X2_1 {
public:
    X2_1 () {
        cout << "X2 constructor called\n";
    }
    ~X2_1 () {
        cout << "X2 destructor called\n";
    }

};

class Y_1 : public X1_1, public X2_1 {
public:
    Y_1() {
        cout << "Y constructor called\n";
    }
    ~Y_1() {
        cout << "Y destructor called\n";
    }
};
void p1() {
    Y_1 y;
}


//to declare both base and derived classes with constructors

class X_2 {
public:
    X_2() {
        cout << "Base constructor called\n";
    }
};

class Y_2 : public X_2 {
public:
    Y_2() {
        cout << "Derived constructor called\n";
    }
};


void p2() {
    Y_2 y;

}


// declare multiple constructors in base class and single constructor in derived class 
class X_3{
    int val;
public: 
    X_3() {
        this->val = 80;
    }
    X_3(int val) {
        this->val = val;
    }
    void printVal() {
        cout << "val = " << val << endl;
    }
};

class Y_3 : public X_3 {
public:
    Y_3(int val) : X_3(val) {
    }
};

void p3() {
    Y_3 y(4);
    y.printVal();
}


// declare base and derived class without default constructor
class X_4 {
public:
    X_4() = delete;
    X_4(int val) {
        cout << "X constructor called with val = " << val << endl;
    }
};
class Y_4 : public X_4 {
public:
    Y_4() = delete;
    Y_4(int val) : X_4(val) {
        cout << "Y constructor called with val = " << val << endl;
    }

};

void p4() {
    Y_4(23);
}

// derive a class using multiple base classes. observe the execution of constructor when object of 
// derived class is declared

class X1_5 {
public:
    X1_5 () {
        cout << "X1 constructor called\n";
    }
};
class X2_5 {
public:
    X2_5 () {
        cout << "X2 constructor called\n";
    }

};
class Y_5 : public X1_5, X2_5 {
public:
    Y_5 () {
        cout << "Y constructor called\n";
    }

};

void p5 () {
    Y_5 y;
}


// derive a class using multiple base classes. invoke the constructors of base classes explicitly

class X1_6 {
public:
    X1_6 () {
        cout << "X1 constructor called\n";
    }    
};
class X2_6 {
public:
    X2_6 () {
        cout << "X2 constructor called\n";
    }
};

class Y_6 : public X1_6, public X2_6 {
public:
    Y_6() : X1_6(), X2_6() {
        cout << "Y constructor called\n";
    }
};
void p6() {
    Y_6 y;
}




// derive a class using multi-level inheritance and observe the execution sequence of construcor
class X_7 {
public:
    X_7() {
        cout << "X constructor called\n";
    }
};
class Y_7 : public X_7 {
public:
    Y_7() {
        cout << "Y constructor called\n";
    }
};
class Z_7 : public Y_7 {
public:
    Z_7() {
        cout << "Z constructor called\n";
    }
};

void p7() {
    Z_7 z;
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