#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // last_pos[x] lưu lượt xuất hiện cuối của tuyệt chiêu x
    // Giá trị mặc định là -1 (chưa xuất hiện)
    static int last_pos[1000001];
    memset(last_pos, -1, sizeof(last_pos));

    int vi_pham = -1; // Lưu mã tuyệt chiêu vi phạm có mã nhỏ nhất, -1 là chưa vi phạm

    for (int i = 0; i < n; i++) {
        int skill = a[i];
        if (last_pos[skill] != -1) {
            // Kiểm tra nếu lượt hiện tại - lượt xuất hiện gần nhất < k => vi phạm
            if (i - last_pos[skill] < k) {
                // Nếu chưa có vi phạm hoặc skill bé hơn skill vi phạm cũ, cập nhật vi_pham
                if (vi_pham == -1 || skill < vi_pham) {
                    vi_pham = skill;
                }
            }
        }
        last_pos[skill] = i;
    }

    cout << vi_pham << "\n";
    return 0;
}