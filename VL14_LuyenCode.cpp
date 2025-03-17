#include <iostream>
#include <cmath>
using namespace std;

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

int main() {
    int a, b;
    cin >> a >> b;

    int result = gcd(a, b);
    cout << result << endl;

    return 0;
}
