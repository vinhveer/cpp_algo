#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Cấu trúc lưu trữ thông tin bông hoa
struct Flower {
    int height;
    int index;
    long long beauty;
};

// Cây chỉ số nhị phân (Binary Indexed Tree/Fenwick Tree)
class BIT {
private:
    vector<long long> tree;
    int size;
    
public:
    BIT(int n) {
        size = n + 1;
        tree.resize(size, 0);
    }
    
    // Cập nhật giá trị tại vị trí idx
    void update(int idx, long long val) {
        idx++; // Chuyển sang index 1-based cho BIT
        while (idx < size) {
            tree[idx] = max(tree[idx], val);
            idx += (idx & -idx); // Thêm bit thấp nhất của idx
        }
    }
    
    // Lấy giá trị lớn nhất từ vị trí 1 đến idx
    long long query(int idx) {
        idx++; // Chuyển sang index 1-based cho BIT
        long long res = 0;
        while (idx > 0) {
            res = max(res, tree[idx]);
            idx -= (idx & -idx); // Trừ bit thấp nhất của idx
        }
        return res;
    }
};

// Hàm nén tọa độ
vector<int> compress(const vector<int>& values) {
    vector<int> sorted = values;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    
    vector<int> compressed(values.size());
    for (size_t i = 0; i < values.size(); i++) {
        compressed[i] = lower_bound(sorted.begin(), sorted.end(), values[i]) - sorted.begin();
    }
    
    return compressed;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<Flower> flowers(n);
    vector<int> heights(n);
    
    // Đọc chiều cao của các bông hoa
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
        flowers[i].height = heights[i];
        flowers[i].index = i;
    }
    
    // Đọc vẻ đẹp của các bông hoa
    for (int i = 0; i < n; i++) {
        cin >> flowers[i].beauty;
    }
    
    // Nén tọa độ chiều cao
    vector<int> compressedHeights = compress(heights);
    for (int i = 0; i < n; i++) {
        flowers[i].height = compressedHeights[i];
    }
    
    // Sắp xếp bông hoa theo thứ tự tăng dần của index (vị trí ban đầu)
    sort(flowers.begin(), flowers.end(), [](const Flower& a, const Flower& b) {
        return a.index < b.index;
    });
    
    // Khởi tạo cây chỉ số nhị phân với kích thước là n
    BIT bit(n);
    
    vector<long long> dp(n);
    long long maxBeauty = 0;
    
    for (int i = 0; i < n; i++) {
        // Tìm tổng vẻ đẹp lớn nhất có thể khi kết thúc tại bông hoa có chiều cao nhỏ hơn flowers[i].height
        long long maxPrevBeauty = bit.query(flowers[i].height - 1);
        
        // Cập nhật dp[i]
        dp[i] = maxPrevBeauty + flowers[i].beauty;
        
        // Cập nhật BIT với chiều cao hiện tại và giá trị dp[i]
        bit.update(flowers[i].height, dp[i]);
        
        // Cập nhật kết quả
        maxBeauty = max(maxBeauty, dp[i]);
    }
    
    cout << maxBeauty << endl;
    
    return 0;
}