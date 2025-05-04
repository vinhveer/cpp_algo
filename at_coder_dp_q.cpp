#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, long long>> flowers(n); // {height, beauty}
    
    // Đọc chiều cao của các bông hoa
    for (int i = 0; i < n; i++) {
        cin >> flowers[i].first;
    }
    
    // Đọc vẻ đẹp của các bông hoa
    for (int i = 0; i < n; i++) {
        cin >> flowers[i].second;
    }
    
    // Mảng dp để lưu trữ tổng vẻ đẹp lớn nhất khi kết thúc tại bông hoa thứ i
    vector<long long> dp(n);
    
    // Khởi tạo mảng dp với vẻ đẹp của từng bông hoa
    for (int i = 0; i < n; i++) {
        dp[i] = flowers[i].second;
    }
    
    // Thuật toán quy hoạch động để tìm dãy con tăng có tổng vẻ đẹp lớn nhất
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (flowers[j].first < flowers[i].first) {
                dp[i] = max(dp[i], dp[j] + flowers[i].second);
            }
        }
    }
    
    // Tìm giá trị lớn nhất trong mảng dp
    long long maxBeauty = 0;
    for (int i = 0; i < n; i++) {
        maxBeauty = max(maxBeauty, dp[i]);
    }
    
    cout << maxBeauty << endl;
    
    return 0;
}