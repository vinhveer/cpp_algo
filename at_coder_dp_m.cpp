#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    // dp[i][j]: số cách chia j viên kẹo cho i đứa trẻ đầu tiên
    vector<int> prev(k + 1, 0);
    vector<int> curr(k + 1, 0);
    
    // Trường hợp cơ sở: có 1 cách để chia 0 viên kẹo cho 0 đứa trẻ
    prev[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        // Sử dụng mảng prefix để tính toán hiệu quả
        vector<int> prefix(k + 2, 0);
        for (int j = 0; j <= k; j++) {
            prefix[j + 1] = (prefix[j] + prev[j]) % MOD;
        }
        
        for (int j = 0; j <= k; j++) {
            // Đứa trẻ thứ i có thể nhận từ 0 đến min(a[i], j) viên kẹo
            int left = j - min(a[i], j);
            int right = j + 1;
            
            // Tính tổng DP[i-1][j], DP[i-1][j-1], ..., DP[i-1][j-min(a[i],j)] bằng tổng tiền tố
            curr[j] = (prefix[right] - prefix[left] + MOD) % MOD;
        }
        
        // Swap để chuẩn bị cho vòng lặp tiếp theo
        prev.swap(curr);
        fill(curr.begin(), curr.end(), 0);
    }
    
    cout << prev[k] << endl;
    
    return 0;
}