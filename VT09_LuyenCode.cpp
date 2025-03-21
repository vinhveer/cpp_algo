#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

bool isPrime(long long num) {
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (long long i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<long long> primes;
    for (int i = 0; i < n; i++){
        long long val;
        cin >> val;
        if (isPrime(val)){
            primes.insert(val);
        }
    }

    for (auto p : primes){
        cout << p << " ";
    }
    cout << "\n";
    return 0;
}
