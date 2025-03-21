#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long L, R;
    cin >> L >> R;
    for (long long i = L; i <= R; i++){
        if (isPrime(i)) {
            cout << i << "\n";
        }
    }

    return 0;
}
