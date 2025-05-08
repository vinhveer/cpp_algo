#include <bits/stdc++.h>
using namespace std;

// We use 64-bit integers (long long) to avoid overflow.
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    long long m; 
    cin >> n >> m;

    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    // Read capacities
    // Warning: in a real scenario, storing r up to m=10^9 is not memory-feasible.
    // We assume it fits the problem's setting.
    vector<long long> r(m+1);
    for(long long i = 1; i <= m; i++){
        cin >> r[i];
    }

    // Build prefix sums p[i] = r[1] + r[2] + ... + r[i].
    vector<long long> p(m+1, 0);
    for(long long i = 1; i <= m; i++){
        p[i] = p[i-1] + r[i];
    }

    // res[i] will store total water that ends up in container i (1-based)
    vector<long long> res(m+1, 0);

    for(int i = 0; i < n; i++){
        long long water = a[i];
        // If there's more water than total capacity, only fill everything.
        if(water >= p[m]){
            // All containers fully filled
            for(long long j = 1; j <= m; j++){
                res[j] += r[j];
            }
            continue;
        }

        // Otherwise, find the largest j such that p[j] <= water
        // This means containers 1..j are fully filled
        long long j = (long long)(upper_bound(p.begin()+1, p.end(), water) - p.begin()) - 1;
        // containers 1..j fully filled
        for(long long c = 1; c <= j; c++){
            res[c] += r[c];
        }
        // partial fill in container j+1, if j < m
        if(j < m){
            long long remain = water - p[j];
            if(remain > 0){
                res[j+1] += remain;
            }
        }
    }

    // Output only non-zero containers
    // Problem statement: "Nếu máy xử lý nước không nhận được nước thì không in ra."
    // We'll print them in one line separated by spaces
    bool firstPrinted = false;
    for(long long i = 1; i <= m; i++){
        if(res[i] > 0){
            if(!firstPrinted){
                cout << res[i];
                firstPrinted = true;
            }
            else {
                cout << " " << res[i];
            }
        }
    }
    cout << "\n";
    return 0;
}