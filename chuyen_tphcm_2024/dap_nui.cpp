#include <bits/stdc++.h>
using namespace std;

/*
  We define:
  - L[i]: final height of A[i] in the minimal strictly-increasing array (from the left),
  - costLeft[i]: total increments needed for indices 1..i,
  - R[i]: final height of A[i] in the minimal strictly-decreasing array (from the right),
  - costRight[i]: total increments needed for indices i..n.

  Then for each candidate peak x (2 <= x <= n-1),
  the cost is computed by:
      cost_x = costLeft[x] + costRight[x]
               - ( (L[x] - A[x]) + (R[x] - A[x]) )  // remove the double-counting of x
               + ( max(L[x], R[x]) - A[x] )        // final cost for the peak x

  We choose the minimum cost_x among all valid x.
*/

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> A(n+1), L(n+1), R(n+1);
    for(int i = 1; i <= n; i++){
        cin >> A[i];
    }

    // Build strictly-increasing-from-left array
    // and its cumulative cost
    vector<long long> costLeft(n+1, 0);
    L[1] = A[1];
    for(int i = 2; i <= n; i++){
        L[i] = max(L[i-1] + 1, A[i]);
        costLeft[i] = costLeft[i-1] + (L[i] - A[i]);
    }

    // Build strictly-decreasing-from-right array
    // and its cumulative cost
    vector<long long> costRight(n+1, 0);
    R[n] = A[n];
    for(int i = n-1; i >= 1; i--){
        R[i] = max(R[i+1] + 1, A[i]);
        costRight[i] = costRight[i+1] + (R[i] - A[i]);
    }

    // Compute minimal total cost for forming a mountain
    // with peak = x, where 2 <= x <= n-1
    long long ans = LLONG_MAX;
    for(int x = 2; x <= n-1; x++){
        long long cost = costLeft[x] + costRight[x]
                         - ((L[x] - A[x]) + (R[x] - A[x]))
                         + (max(L[x], R[x]) - A[x]);
        ans = min(ans, cost);
    }

    cout << ans << "\n";
    return 0;
}