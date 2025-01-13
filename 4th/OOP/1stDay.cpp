#include <iostream>
using namespace std;


void p1(), p2(), p3(), p4();
int main () {
    p1();
    p2();
    p3();
    p4();

    return 0;
}
// check even odd
void p1() {
    int n;
    cout << "Enter num: ";
    cin >> n;
    if ((n & 1) == 0) cout << "Even";
    else cout << "Odd";
    cout << endl;
}

// sum of two nums
void p2() {
    int a, b;
    cout << "Enter two nums: ";
    cin >> a >> b;
    cout << "Sum: " << (a+b) << endl;
}

// check leap year
void p3() {
    int n;
    cout << "Enter year: ";
    cin >> n;
    if (n % 400 == 0) {
        cout << n << " is a leap year.";
    } else if ((n % 100 != 0) && (n % 4 == 0)) {
        cout << n << " is a leap year.";
    } else {
        cout << n << " is not a leap year.";
    }
    cout << endl;

}

// max of 3 nums
void p4() {
    int a,b,c;
    cout << "Enter three nums: ";
    cin >> a >> b >> c;
    cout << "Max: " << max(a, max(b, c)) << endl;
}