#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s, t;
    cin >> s >> t;
    
    int n = s.length();
    int m = t.length();
    
    // dp[i][j] là độ dài của xâu con chung dài nhất của s[0...i-1] và t[0...j-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    // Điền bảng DP
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    // Truy vết để tìm xâu con chung dài nhất
    string lcs = "";
    int i = n, j = m;
    
    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            lcs = s[i - 1] + lcs;
            i--;
            j--;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    
    cout << lcs << endl;
    
    return 0;
}