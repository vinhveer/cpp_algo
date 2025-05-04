#include <iostream>
using namespace std;

long long phi(long long n)
{
    long long result = n;
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            while (n % i == 0)
            {
                n /= i;
            }
            result -= result / i;
        }
    }

    if (n > 1) {
        result -= result / n;
    }

    return result;
}

int main()
{
    while (true)
    {
        long long N;
        cin >> N;

        if (!cin || N == 0) break;

        long long s = 0;

        for (long long d = 1; d <= N; d++) {
            long long m = N / d;
            s += phi(d) * m * m;
        }

        long long diag = N * (N + 1) / 2;
        long long ans = (s - diag) / 2;

        cout << ans << endl;
    }

    return 0;
}
