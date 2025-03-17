#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Hàm cộng hai số nguyên lớn
string addLargeNumbers(string num1, string num2) {
    // Đảm bảo num1 có độ dài lớn hơn hoặc bằng num2
    if (num1.length() < num2.length())
        swap(num1, num2);

    string result = "";
    size_t n1 = num1.length(), n2 = num2.length();
    int carry = 0;

    // Đảo ngược hai chuỗi để dễ tính toán
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    // Thực hiện phép cộng
    for (size_t i = 0; i < n2; i++) {
        int sum = (num1[i] - '0') + (num2[i] - '0') + carry;
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    // Tiếp tục thêm các chữ số còn lại từ num1
    for (size_t i = n2; i < n1; i++) {
        int sum = (num1[i] - '0') + carry;
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    // Thêm carry nếu còn
    if (carry)
        result.push_back(carry + '0');

    // Đảo ngược kết quả để được số nguyên cuối cùng
    reverse(result.begin(), result.end());

    return result;
}

int main() {
    string a, b;

    // Nhập dữ liệu
    cin >> a >> b;

    // Tính toán và in kết quả
    cout << addLargeNumbers(a, b) << endl;

    return 0;
}
