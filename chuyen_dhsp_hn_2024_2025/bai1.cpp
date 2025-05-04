#include <bits/stdc++.h>
using namespace std;

// Hàm tính UCLN
long long gcdCalc(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// Trả về danh sách các ước của n
vector<long long> getDivisors(long long n) {
    vector<long long> divisors;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i * i != n) {
                divisors.push_back(n / i);
            }
        }
    }
    return divisors;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    vector<long long> dList = getDivisors(n);
    long long bestM = 1;
    long long bestValue = -1;

    for (auto d : dList) 
    {
        long long t = n / d;
        long long k = (n - 2) / d;

        while (k > 0 && gcdCalc(k, t) != 1) {
            k--;
        }

        if (k <= 0) continue;

        long long value = d * (k + 1);
        long long mVal = d * k;
        
        if (mVal < 1 || mVal >= n - 1) continue;

        if (value > bestValue) {
            bestValue = value;
            bestM = mVal;
        } else if (value == bestValue && mVal > bestM) {
            bestM = mVal;
        }
    }

    cout << bestM << "\n";

    return 0;
}