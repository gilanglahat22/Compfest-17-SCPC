#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define setbits(x) __builtin_popcountll(x)
#define trailing_zeros(x) __builtin_ctzll(x)
#define leading_zeros(x) __builtin_clzll(x)
#define sz(v) (int)v.size()
#define ps(y) cout << fixed << setprecision(y)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define trav(x, v) for(auto &x: v)
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define rrep(i, a, b) for(int i = a; i >= b; i--)
#define rep0(i, n) rep(i, 0, n - 1)
#define rrep0(i, n) rrep(i, n - 1, 0)
#define rep1(i, n) rep(i, 1, n)
#define rrep1(i, n) rrep(i, n, 1)
#define inp(arr, n) rep0(i, n) cin >> arr[i];

void solve() {
    int n;
    string s;
    cin >> n >> s;
    if (n == 3) {
        if (s[0] == s[1] || s[1] == s[2] || s[0] == s[2]) {
            cout << 7 << endl;
        } else {
            cout << 6 << endl;
        }
    } else {
        ll ans = 1;
        rep1(i, n) {
            ans = (ans * i) % MOD;
        }
        cout << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}