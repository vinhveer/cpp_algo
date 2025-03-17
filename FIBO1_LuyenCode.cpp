#include <bits/stdc++.h>
using namespace std;

// Hàm cộng 2 số lớn dạng chuỗi
string bigAdd(const string &a, const string &b) {
    // Đảo chuỗi để cộng
    string ra = a;
    string rb = b;
    reverse(ra.begin(), ra.end());
    reverse(rb.begin(), rb.end());

    int carry = 0;
    int len = max(ra.size(), rb.size());
    string result;
    result.reserve(len + 1);

    for (int i = 0; i < len; i++) {
        int x = (i < (int)ra.size()) ? (ra[i] - '0') : 0;
        int y = (i < (int)rb.size()) ? (rb[i] - '0') : 0;
        int sum = x + y + carry;
        carry = sum / 10;
        result.push_back(char(sum % 10 + '0'));
    }
    if (carry) {
        result.push_back(char(carry + '0'));
    }
    reverse(result.begin(), result.end());
    return result;
}

// Tính F(n) với F(0)=1, F(1)=1 chuỗi lớn
// Ở đây ta sẽ tính tất cả F(i) từ 0..maxN.
// Chú ý: Do đề không nói rõ giới hạn n, ta giả sử n tương đối vừa phải.
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    vector<long long> queries(T);
    long long maxN = 0;
    for(int i = 0; i < T; i++){
        cin >> queries[i];
        maxN = max(maxN, queries[i]);
    }

    // Nếu maxN = 0, chỉ cần in 1 (F(0)=1)
    // Nếu maxN=1, in 1 (F(1)=1)
    // Ngược lại, ta cộng dồn
    // Lưu tất cả Fibonacci vào mảng fibStrings theo dạng chuỗi
    vector<string> fibStrings(maxN + 1);

    // F(0)=1
    fibStrings[0] = "1";
    // Nếu có n>=1
    if(maxN >= 1){
        fibStrings[1] = "1";
    }

    // Tính F(n) = F(n-1) + F(n-2) cho n >= 2
    for(long long i = 2; i <= maxN; i++){
        fibStrings[i] = bigAdd(fibStrings[i-1], fibStrings[i-2]);
    }

    // Xuất kết quả
    for(int i = 0; i < T; i++){
        cout << fibStrings[queries[i]] << "\n";
    }

    return 0;
}
