#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;


// A university wants to maintain consistency in storing student names in their database.
// To achieve this, they require a program that can process and format student names.
// Create a Student class that accepts the student's full name as input and provides functionalities
// to convert the name to uppercase, extract the first name and last name separately, and rearrange 
// the name in reverse order as "Last Name First Name" (e.g., "John Doe" becomes "Doe John"). 
// The program should demonstrate the use of encapsulation to manage the data and operations related
// to the student's name within the class. Ensure proper input handling and formatted output while
// showcasing object-oriented principles.

class Student {
private:
    string firstName;
    string lastName;

public:
    Student (string fullName) {
        int pos = fullName.find(' ');
        firstName = fullName.substr(0, pos);
        lastName = fullName.substr(pos+1, fullName.size() - pos);
    }
    string toUpper() {
        string str = firstName + " " + lastName;
        transform(str.begin(), str.end(), str.begin(), ::toupper);
        return str;
    }
    string getFirstName() {
        return firstName;
    }
    string getLastName() {
        return lastName;
    }
    string getReversed() {
        return (lastName + " " + firstName);
    }
};

void p1() {
    cout << "Enter name: ";
    string first, last;
    cin >> first >> last;
    Student st(first + " " + last);
    cout << "Uppercase: " << st.toUpper() << endl;
    cout << "First Name: " << st.getFirstName() << endl;
    cout << "Last Name: " << st.getLastName() << endl;
    cout << "Reversed: " << st.getReversed() << endl;
}




// All the banks operating in India are controlled by RBI. RBI has set a well-defined guideline 
// (e.g. minimum interest rate, minimum balance allowed, maximum withdrawal limit etc) which 
// all banks must follow. For example, suppose RBI has set minimum interest rate applicable to a
// saving bank account to be 4% annually; however, banks are free to use 4% interest rate or to 
// set any rates above it. Write a C++ program to implement bank functionality in the above scenario
// and demonstrate the dynamic polymorphism concept. Note: Create few classes namely Customer, 
// Account, RBI (Base Class) and few derived classes (SBI, ICICI, PNB etc). Assume and implement 
// required member variables and functions in each class.


class RBI {
public:
    static float minInterestRate, minBalance, maxWithdrawLim;
};
float RBI::minInterestRate = 4, RBI::minBalance = 500;

class Bank : public RBI {
    float minInterestRate, minBalance, maxWithdrawLim;
public:
    void setMinInterestRate(float rate) {
        if (rate >= RBI::minInterestRate) {
            this->minInterestRate = rate;
        } else {
            cout << "Interest Rate must be atleast " << RBI::minInterestRate << endl;
        }
    }
    float getMinInterestRate() {
        return this->minInterestRate;
    }
};

class SBI: public Bank {
public: 
    SBI() {
        setMinInterestRate(4.5);
    }
};
class PNB: public Bank {
public:
    PNB() {
        setMinInterestRate(6.4);
    }
};

class Account {
    RBI* bank;
    string acNum;
    float balance;
public:
    Account(RBI* bank, string acNum, float balance) : bank(bank), acNum(acNum) {
        if (balance >= bank->minBalance) {
            this->balance = balance;
        } else {
            cout << "Balance must be atleast " << bank->minBalance << endl;
        }
    }
    void showDetails () {
        cout << "Account No.: " << acNum << "\nBalance: " << balance << endl;
     }
};

class Customer {
    string name;
    Account* account;
public:
    Customer(string name, Account* account) : name(name), account(account) {}
};


void p2() {
    SBI sbi; 
    PNB pnb;

    Account ac1(&sbi, "12345678", 30000), ac2(&pnb, "77889900", 20000);
    Customer cust1("Bruce Wayne", &ac1), cust2("Tony Stark", &ac2);
    cout << sbi.getMinInterestRate() << endl;
    cout << pnb.getMinInterestRate() << endl;
    cout << RBI::minInterestRate << endl;
    ac1.showDetails();
    ac2.showDetails();
}





// Write a Program that does the following related to Inheritance: 
// a) Create an abstract class called Vehicle which contains the ‘year of manufacture’ data member 
//    and two abstract methods getdata() and putdata() with a constructor. 
// b) Create two derived classes ‘Two-wheeler’ and ‘Four-wheeler’ 
//    and implement the abstract methods. Make ‘Four-wheeler’ as final class.
// c) Create class ‘MyTwoWheeler’ which is a subclass of ‘Two-wheeler’ and demonstrate the use of 
//    super keyword to initialize data members of ‘MyTwoWheeler’
class Vehicle {
protected:
    int yearOfMfg;
    virtual int getdata() = 0;
    virtual void putdata(int data) = 0;
};

class TwoWheeler : public Vehicle {
public:
    TwoWheeler(int yearOfMfg) {this->yearOfMfg = yearOfMfg;}
    virtual int getdata() override {
        return yearOfMfg;
    }
    virtual void putdata (int data) override {
        yearOfMfg = data;
    }
};

class FourWheeler final : public Vehicle {
public:
    int getdata() {
        return yearOfMfg;
    }
    void putdata(int data) {
        yearOfMfg = data;
    }
};
class MyTwoWheeler : public TwoWheeler {
public:
    MyTwoWheeler(int yearOfMfg) : TwoWheeler(yearOfMfg) {};
};

void p3() {
    FourWheeler fw;
    fw.putdata(1990);
    cout << fw.getdata() << endl;
    MyTwoWheeler mtw(1979);
    cout << mtw.getdata() << endl;
    mtw.putdata(2005);
    cout << mtw.getdata() << endl;
}


// Write a program to create an abstract class namely Shape that contains two integers and an empty
// method named print Area (). Provide three classes named Rectangle, Triangle, and Circle such that
// each one of the classes extends the class Shape. Each one of the classes contains only the method 
// print Area () that prints the area of the given shape.


class Shape {
protected:
    int a, b;
    virtual void printArea() = 0;
};
class Rectangle : public Shape {
public:
    Rectangle (int b, int h) {
        this->a = b;
        this->b = h;
    } 
    virtual void printArea () override {
        cout << a * b << endl;
    }
};
class Triangle : public Shape {
public:
    Triangle (int b, int h) {
        this->a = b;
        this->b = h;
    } 
    virtual void printArea () override {
        cout << 0.5 * a * b << endl;
    }
};
class Circle : public Shape {
public:
    Circle (int r) {
        this->a = r;
    } 
    virtual void printArea () override {
        cout << 3.141 * a * a << endl;
    }
};

void p4() {
    Rectangle rec(6, 8);
    Triangle tri(4, 8);
    Circle cir(6);
    rec.printArea();
    tri.printArea();
    cir.printArea();
}


// A data analytics tool requires the ability to analyze the frequency of characters in a given string.
// Create a FrequencyAnalyzer class that accepts a string as input and provides a method to count the 
// frequency of each character. The program should display the frequencies in descending order of 
// occurrence, making it easy to identify the most frequently used characters. Write a program to 
// analyze and display the character frequencies for various input strings.

class FrequencyAnalyzer {
    map<char,int> freq;
    vector<pair<char,int>> vec;
    string s;
public:
    FrequencyAnalyzer (string s) : s(s) {
        for (auto& c : s) freq[c]++;
        for (auto& p : freq) vec.push_back(p);
        sort(vec.begin(), vec.end(), [](auto& p1, auto& p2) {
            return p1.second > p2.second;
        });
    }
    void displayFreq () {
        for (auto& p : vec) cout << p.first << ": " << p.second << endl;
    }
};

void p5() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    FrequencyAnalyzer fa(s);
    fa.displayFreq();
}



int main() {
    p1();
    p2();
    p3();
    p4();
    p5();

    return 0;
}