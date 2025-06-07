#include <iostream>
using namespace std;

// Extended Euclidean Algorithm to find gcd and coefficients x, y
int extendedGCD(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;  // Coefficient of a
        y = 0;  // Coefficient of b
        return a;
    }
    int x1, y1;
    int gcd = extendedGCD(b, a % b, x1, y1);
    
    // Update x and y using the results of recursive call
    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

// Function to find modular inverse of a modulo m
int modInverse(int a, int m) {
    int x, y;
    int gcd = extendedGCD(a, m, x, y);

    if (gcd != 1) {
        // Modular inverse doesn't exist
        cout << "Modular inverse doesn't exist for a = " << a << " and m = " << m << endl;
        return -1;
    }

    // Ensure the result is positive
    return (x % m + m) % m;
}

int main() {
    int a = 17, m = 43;

    int inverse = modInverse(a, m);
    if (inverse != -1)
        cout << "The modular inverse of " << a << " modulo " << m << " is " << inverse << endl;

    return 0;
}
