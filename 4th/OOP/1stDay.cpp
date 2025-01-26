#include <iostream>
#include <cmath>
#include <string>
using namespace std;


void p1(), p2(), p3(), p4();
void p5(), p6(), p7(), p8();
int main () {
    // p1();
    // p2();
    // p3();
    // p4();
    p5();
    p6();
    p7();
    p8();

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


bool isPrime(int n) {
    if (n == 2) return true;
    if ((n < 2) || (n % 2 == 0)) return false;

    int s = sqrt(n);
    for (int i = 3; i <= s; i += 2) {
        if (isPrime(i) && (n % i == 0)) return false;
    }
    return true;
}

// prime or not
void p5 () {
    int n;
    cout << "Enter num: ";
    cin >> n;
    if (isPrime(n)) cout << "Prime" << endl;
    else cout << "Not Prime" << endl;

}


// palindrome check
void p6 () {
    string s;
    cout << "Enter string: ";
    cin >> s;
    int n = s.size();
    for (int i = 0; i <= n/2; i++) {
        if (s[i] != s[n-i-1]) {
            cout << "Not palindrome" << endl;
            return;
        }
    }
    cout << "Palindrome" << endl;
}


// armstrong num
void p7 () {
    string s;
    cout << "Enter num: ";
    cin >> s;
    int n = stol(s);
    int sum = 0;
    for (char& c : s) {
        sum += pow(c - '0', s.size());
    }
    
    if (n == sum) cout << n << " is an Armstrong Number" << endl;
    else cout << n << " is not an Armstrong Number" << endl;
    
}



// check vowel or consonant using switch case
void p8 () {
    char c;
    cout << "Enter letter: ";
    cin >> c;
    c = tolower(c);
    switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            cout << "Vowel" << endl;
            break;
        default:
            cout << "Consonant" << endl;
            break;
    }

}
