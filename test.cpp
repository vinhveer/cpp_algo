#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> adjacency(n * n);
    for (int i = 0; i < n * n; i++) {
        cin >> adjacency[i];
    }


    int total_ones = 0;
    for (int val : adjacency) {
        total_ones += val;
    }

    cout << total_ones / 2 << "\n";
    return 0;
}