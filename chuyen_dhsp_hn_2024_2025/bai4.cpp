#include <bits/stdc++.h>
using namespace std;

string maxStrictlyIncreasing(string s)
{
    if (s == "0")
        return "0";

    int n = (int)s.size();

    vector<int> digits(n);
    for (int i = 0; i < n; i++)
    {
        digits[i] = s[i] - '0';
    }

    int idx = -1;
    for (int i = 0; i < n - 1; i++)
    {
        if (digits[i] >= digits[i+1]) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        return s;
    }

    digits[idx]--;

    while (idx > 0 && digits[idx] <= digits[idx - 1]) {
        digits[idx - 1]--;
        idx--;
    }

    for (int i = 0; i <= idx; i++) {
        if (digits[i] < 0) digits[i] = 0;
    }

    for (int i = idx + 1; i < n; i++) {
        int prev = digits[i - 1];

        if (prev < 9)
        {
            digits[i] = prev + 1;
        }
        else digits[i] = -1;
    }

    vector<int> result;
    result.reserve(n);
    for (int d : digits) {
        if (d >= 0) {
            result.push_back(d);
        } else {
            break;
        }
    }

    int pos = 0;
    while (pos < (int) result.size() && result[pos] == 0) {
        pos++;
    }
    if (pos == (int)result.size()) {
        return "0";
    }

    string ans;
    for (int i = pos; i < (int) result.size(); i++) {
        ans.push_back((char)('0' + result[i]));
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        long long a;
        cin >> a;

        if (a == 0)
        {
            cout << 0 << "\n";
            continue;
        }

        string s = to_string(a);
        string ans = maxStrictlyIncreasing(s);

        if (ans.size() > s.size() || (ans.size() == s.size() && ans > s)) {
            long long val = stoll(ans);
            while (val > a) {
                val--;
            }

            ans = maxStrictlyIncreasing(to_string(val));
        }

        cout << ans << "\n";
    }

    return 0;
}