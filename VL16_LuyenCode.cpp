#include <iostream>
#include <cmath>
using namespace std;

// GCD function from previous solution
int gcd(int a, int b) {
    // Convert to absolute values since GCD is always positive
    a = abs(a);
    b = abs(b);

    // Handle special case where one number is 0
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    // Euclidean algorithm
    while (b) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

// LCM function
int lcm(int a, int b) {
    // LCM is always positive, but we need to handle negative numbers
    // LCM(a, b) = |a × b| / GCD(a, b)

    // Calculate GCD
    int gcdValue = gcd(a, b);

    // Calculate LCM
    // Using long long to avoid integer overflow
    long long product = (long long)abs(a) * abs(b);
    return product / gcdValue;
}

int main() {
    int a, b;
    cin >> a >> b;

    int result = lcm(a, b);
    cout << result << endl;

    return 0;
}
