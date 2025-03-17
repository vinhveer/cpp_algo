#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    // Initialize first two Fibonacci numbers
    vector<long long> fib(n);
    fib[0] = 1;
    fib[1] = 1;

    // Generate the Fibonacci sequence
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    // Print the first n Fibonacci numbers
    for (int i = 0; i < n; i++) {
        cout << fib[i];
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
