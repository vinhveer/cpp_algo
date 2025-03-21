#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (long long i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    if (n < 4) {
        cout << 0 << "\n";
        return 0;
    }

    // We check if there exist p (prime) and k >= 2 such that p^k = n
    // We'll try k from 2 up to log2(n) (since 2^k is the smallest base).
    bool found = false;
    int maxK = floor(log2(n));
    for (int k = 2; k <= maxK; k++){
        // approximate the base
        long long p = (long long)floor(pow((long double)n, 1.0L / k));
        // check p^k and (p+1)^k to handle rounding issues
        // (p+1)^k might be close to n if p^k < n
        long long power1 = 1, power2 = 1;
        for (int i = 0; i < k; i++){
            power1 *= p;
            power2 *= (p + 1);
        }
        if ((power1 == n && isPrime(p)) || (power2 == n && isPrime(p + 1))) {
            found = true;
            if (power1 == n && isPrime(p)) {
                cout << p << " " << k << "\n";
            } else {
                cout << p + 1 << " " << k << "\n";
            }
            break;
        }
    }

    if (!found) cout << 0 << "\n";

    return 0;
}
