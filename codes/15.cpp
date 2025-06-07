#include <iostream>
using namespace std;

// Function to compute (base^exp) % mod using fast exponentiation
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

// Function to compute modular inverse of 'a' modulo prime 'p'
long long modInverse(long long a, long long p) {
    return power(a, p - 2, p); // Fermat's Little Theorem
}

int main() {
    long long a, p;
    cout << "Enter a and prime p: ";
    cin >> a >> p;

    if (__gcd(a, p) != 1) {
        cout << "Modular inverse doesn't exist since gcd(a, p) ≠ 1\n";
    } else {
        cout << "Modular Inverse of " << a << " mod " << p << " = " << modInverse(a, p) << endl;
    }

    return 0;
}
