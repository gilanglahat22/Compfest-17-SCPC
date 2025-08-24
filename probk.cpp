#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int sz, limit, step, lo, hi, center, ans;
vector<int> arr, temp;
ll cost;

void solve() {
    lo = 0;
    hi = sz;
    ans = 0;
    while (lo <= hi) {
        center = lo + (hi - lo) / 2;
        temp.clear();
        for (int i = 0; i < center; i++) {
            temp.push_back(arr[i]);
        }
        sort(temp.begin(), temp.end(), greater<int>());
        cost = 0;
        for (int i = 0; i < center; i += step) {
            cost += temp[i];
        }
        if (cost > limit) {
            hi = center - 1;
        } else {
            ans = center;
            lo = center + 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> sz >> limit >> step;
    arr.resize(sz);
    for (int i = 0; i < sz; i++) {
        cin >> arr[i];
    }
    solve();
    return 0;
}