#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

// Hàm cộng hai số nguyên lớn
string addLargeNumbers(string num1, string num2) {
    // Đảm bảo num1 có độ dài lớn hơn hoặc bằng num2
    if (num1.length() < num2.length())
        swap(num1, num2);

    string result = "";
    int n1 = num1.length(), n2 = num2.length();
    int carry = 0;

    // Đảo ngược hai chuỗi để dễ tính toán
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    // Thực hiện phép cộng
    for (int i = 0; i < n2; i++) {
        int sum = (num1[i] - '0') + (num2[i] - '0') + carry;
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    // Tiếp tục thêm các chữ số còn lại từ num1
    for (int i = n2; i < n1; i++) {
        int sum = (num1[i] - '0') + carry;
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    // Thêm carry nếu còn
    if (carry)
        result.push_back(carry + '0');

    // Đảo ngược kết quả để được số nguyên cuối cùng
    reverse(result.begin(), result.end());

    // Loại bỏ các số 0 ở đầu
    size_t startPos = 0;
    while (startPos < result.length() - 1 && result[startPos] == '0')
        startPos++;

    return result.substr(startPos);
}

// Hàm so sánh hai số nguyên lớn, trả về true nếu num1 >= num2
bool isGreaterEqual(string num1, string num2) {
    if (num1.length() != num2.length())
        return num1.length() > num2.length();

    return num1 >= num2;
}

// Hàm trừ hai số nguyên lớn, yêu cầu num1 >= num2
string subtractLargeNumbers(string num1, string num2) {
    bool negative = false;

    // Nếu num1 < num2, đổi chỗ và đặt cờ kết quả là âm
    if (!isGreaterEqual(num1, num2)) {
        swap(num1, num2);
        negative = true;
    }

    string result = "";
    int n1 = num1.length(), n2 = num2.length();

    // Đảo ngược hai chuỗi để dễ tính toán
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    int carry = 0;

    // Thực hiện phép trừ
    for (int i = 0; i < n2; i++) {
        int sub = (num1[i] - '0') - (num2[i] - '0') - carry;

        if (sub < 0) {
            sub += 10;
            carry = 1;
        } else {
            carry = 0;
        }

        result.push_back(sub + '0');
    }

    // Xử lý các chữ số còn lại từ num1
    for (int i = n2; i < n1; i++) {
        int sub = (num1[i] - '0') - carry;

        if (sub < 0) {
            sub += 10;
            carry = 1;
        } else {
            carry = 0;
        }

        result.push_back(sub + '0');
    }

    // Đảo ngược kết quả
    reverse(result.begin(), result.end());

    // Loại bỏ các số 0 ở đầu
    size_t startPos = 0;
    while (startPos < result.length() - 1 && result[startPos] == '0')
        startPos++;

    // Thêm dấu trừ nếu kết quả là âm
    if (negative && result.substr(startPos) != "0")
        return "-" + result.substr(startPos);

    return result.substr(startPos);
}

// Hàm nhân hai số nguyên lớn
string multiplyLargeNumbers(string num1, string num2) {
    // Nếu một trong hai số là 0 thì kết quả là 0
    if (num1 == "0" || num2 == "0")
        return "0";

    int n1 = num1.length();
    int n2 = num2.length();

    // Mảng lưu kết quả, có độ dài tối đa là n1 + n2
    vector<int> result(n1 + n2, 0);

    // Chỉ số để theo dõi vị trí trong kết quả
    int index1 = 0;
    int index2 = 0;

    // Thực hiện phép nhân từ phải sang trái cho num1
    for (int i = n1 - 1; i >= 0; i--) {
        int carry = 0;
        int digit1 = num1[i] - '0';

        index2 = 0;

        // Thực hiện phép nhân từ phải sang trái cho num2
        for (int j = n2 - 1; j >= 0; j--) {
            int digit2 = num2[j] - '0';

            // Tính tổng: phép nhân hiện tại + kết quả trước đó + số nhớ
            int sum = digit1 * digit2 + result[index1 + index2] + carry;

            // Cập nhật số nhớ
            carry = sum / 10;

            // Lưu kết quả
            result[index1 + index2] = sum % 10;

            index2++;
        }

        // Thêm số nhớ vào kết quả
        if (carry > 0)
            result[index1 + index2] += carry;

        index1++;
    }

    // Chuyển mảng kết quả thành chuỗi
    string s = "";

    // Bỏ qua các số 0 ở cuối mảng (đầu số)
    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0)
        i--;

    // Nếu tất cả đều là 0, trả về "0"
    if (i < 0)
        return "0";

    // Chuyển các chữ số thành chuỗi
    while (i >= 0)
        s += to_string(result[i--]);

    return s;
}

int main() {
    string A, B;

    // Nhập dữ liệu
    cin >> A >> B;

    // Tính toán và in kết quả
    cout << addLargeNumbers(A, B) << endl;
    cout << subtractLargeNumbers(A, B) << endl;
    cout << multiplyLargeNumbers(A, B) << endl;

    return 0;
}
