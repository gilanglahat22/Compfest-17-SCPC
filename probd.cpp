#include <bits/stdc++.h>
using namespace std;

int groups, n, k;
long long currSum, totalSum, maxElement, mid, l, r, ans;
vector<long long> A;

bool canPartition(long long maxSum) {
    groups = 1;
    currSum = 0;
    
    for (int i = 0; i < A.size(); i++) {
        if (A[i] > maxSum) return false;
        
        if (currSum + A[i] <= maxSum) {
            currSum += A[i];
        } else {
            groups++;
            currSum = A[i];
            if (groups > k) return false;
        }
    }
    
    return groups <= k;
}

void solve() {
    l = maxElement;
    r = totalSum;
    ans = r;
    
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (canPartition(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    
    cout << ans << "\n";
}

int main() {
    cin >> n >> k;
    
    A.resize(n);
    totalSum = 0;
    maxElement = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        totalSum += A[i];
        maxElement = max(maxElement, A[i]);
    }
    
    solve();
    
    A.clear();
    return 0;
}