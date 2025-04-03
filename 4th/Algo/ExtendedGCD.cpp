#include <iostream>
using namespace std;

void extended_gcd(int a, int b) {
    int r_old = a, r = b;
    int s_old = 1, s = 0;
    int t_old = 0, t = 1, temp;
    while (r != 0) {
        int q = r_old / r;
        temp = r;
        r = r_old - q * r;
        r_old = temp;
        temp = s;
        s = s_old - q * s;
        s_old = temp;
        temp = t;
        t = t_old - q * t;
        t_old = temp;
    }
    cout << "Bézout coefficients: " << s_old << " " << t_old << endl;
    cout << "Greatest Common Divisor: " << r_old << endl;
    cout << "Quotients by the GCD: " << abs(t) << " " << abs(s) << endl;
    
}


int main() {
    int a, b;
    cout << "Enter a and b: ";
    cin >> a >> b;
    extended_gcd(a, b);
    
    return 0;
}


// function extended_gcd(a, b)
//     (old_r, r) := (a, b)
//     (old_s, s) := (1, 0)
//     (old_t, t) := (0, 1)
    
//     while r ≠ 0 do
//         quotient := old_r div r
//         (old_r, r) := (r, old_r − quotient × r)
//         (old_s, s) := (s, old_s − quotient × s)
//         (old_t, t) := (t, old_t − quotient × t)
    
//     output "Bézout coefficients:", (old_s, old_t)
//     output "greatest common divisor:", old_r
//     output "quotients by the gcd:", (t, s)