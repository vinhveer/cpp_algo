#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string addLargeNumbers(string number1, string number2)
{
    // Kiểm tra xem số nào lớn hơn, để hoán đổi vị trí
    if (number1.length() < number2.length()) swap(number1, number2);

    // Lưu kết quả
    string result = "";

    // Lưu độ dài
    int number1_length = number1.length();
    int number2_length = number2.length();

    // Lưu số dư
    int carry = 0;

    // Đảo ngược hai chuỗi
    reverse(number1.begin(), number1.end());
    reverse(number2.begin(), number2.end());

    for (int i = 0; i < number2_length; i++)
    {
        /*
        Tính tổng hai ký tự số tại vị trí thứ i, lấy số nguyên bằng cách trừ
        ký tự số 0 cho ký tự số tại vị trí thứ i
        */
        int sum = (number1[i] - '0') + (number2[i] - '0') + carry;

        /*
        Lấy số đầu tiên và push_back vào mảng result, tuy nhiên phải chuyển
        về dạng string
        */
        result.push_back(sum % 10 + '0');
        // Một số nguyên chia cho một số nguyên -> div
        carry = sum / 10;
    }

    for (int i = number2_length; i < number1_length; i++)
    {
        int sum = (number1[i] - '0') + carry;
        result.push_back(sum % 10 + '0');
        carry = sum / 10;
    }

    if (carry) result.push_back(carry + '0');

    reverse(result.begin(), result.end());

    size_t startPos = 0;
    while (startPos < result.length() && result[startPos] == 0) startPos++;

    return result.substr(startPos);
}

int main()
{
    cout << addLargeNumbers("229933", "388373");

    return 0;
}
