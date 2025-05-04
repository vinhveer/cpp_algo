#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, W;
    cin >> N >> W;
    
    vector<int> weights(N+1);
    vector<long long> values(N+1);
    
    for (int i = 1; i <= N; i++) {
        cin >> weights[i] >> values[i];
    }
    
    // Chỉ cần 1 mảng 1D để tối ưu bộ nhớ
    vector<long long> dp(W+1, 0);
    
    for (int i = 1; i <= N; i++) {
        // Phải duyệt từ phải qua trái để tránh trường hợp 1 món đồ được chọn nhiều lần
        for (int w = W; w >= weights[i]; w--) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }
    
    cout << dp[W] << endl;
    
    return 0;
}