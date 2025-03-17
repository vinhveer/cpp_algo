#include <bits/stdc++.h>
using namespace std;

// Giả sử ta cần tính tới N tối đa 1.000.000 (tùy đề bài, có thể điều chỉnh)
static const int MAXN = 1000000;
long long phiArr[MAXN + 1];

// Sàng để tính hàm phi(d) cho d = 1..MAXN
void computePhi() {
    iota(phiArr, phiArr + MAXN + 1, 0LL);
    for (int i = 2; i <= MAXN; i++) {
        if (phiArr[i] == i) {
            for (int j = i; j <= MAXN; j += i) {
                phiArr[j] -= phiArr[j] / i;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    computePhi();  // Tính mảng phi một lần duy nhất

    while (true) {
        long long N;
        cin >> N;
        if (!cin || N == 0) {
            break; // Kết thúc khi gặp N=0
        }

        long long s = 0;
        // Tính S(N) = ∑(d=1..N) phi(d) × (⌊N/d⌋)²
        for (long long d = 1; d <= N; d++) {
            long long m = N / d;
            s += phiArr[d] * m * m;
        }

        // Trừ đi tổng i=1..N (là N(N+1)/2), rồi chia 2
        long long diag = N * (N + 1) / 2;
        long long ans = (s - diag) / 2;

        cout << ans << "\n";
    }

    return 0;
}
