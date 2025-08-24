#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

#define ff                  first
#define ss                  second
#define pb                  push_back
#define eb                  emplace_back
#define mp                  make_pair
#define lb                  lower_bound
#define ub                  upper_bound
#define setbits(x)          __builtin_popcountll(x)
#define trailing_zeros(x)   __builtin_ctzll(x)
#define leading_zeros(x)    __builtin_clzll(x)
#define sz(v)               (int)v.size()
#define ps(y)               cout << fixed << setprecision(y)
#define ms(arr, v)          memset(arr, v, sizeof(arr))
#define all(v)              v.begin(), v.end()
#define rall(v)             v.rbegin(), v.rend()
#define trav(x, v)          for(auto &x: v)
#define w(t)                int t; cin >> t; while(t--)
#define rep(i, a, b)        for(int i = a; i <= b; i++)
#define rrep(i, a, b)       for(int i = a; i >= b; i--)
#define rep0(i, n)          rep(i, 0, n - 1)
#define rrep0(i, n)         rrep(i, n - 1, 0)
#define rep1(i, n)          rep(i, 1, n)
#define rrep1(i, n)         rrep(i, n, 1)
#define inp(arr, n)         rep0(i, n) cin >> arr[i];
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef map<ll, ll> mii;
typedef map<char, ll> mci;
typedef priority_queue<ll> pq_mx;
typedef priority_queue<ll, vi, greater<>> pq_mn;
/*
 * find_by_order(i) -> returns an iterator to the element at ith position (0 based)
 * order_of_key(i)  -> returns the position of element i (0 based)
 */

ll q,l,r;
struct Mat {
    ll a, b, c, d;
    Mat operator*(const Mat &o) const {
        return {
            (a*o.a + b*o.c) % MOD,
            (a*o.b + b*o.d) % MOD,
            (c*o.a + d*o.c) % MOD,
            (c*o.b + d*o.d) % MOD
        };
    }
};
Mat pow_mat(Mat m, ll n) {
    Mat res = {1, 0, 0, 1};
    while (n) {
        if (n & 1) res = res * m;
        m = m * m;
        n >>= 1;
    }
    return res;
}

void solve(){
    cin >> q;
    while (q--) {
        cin >> l >> r;
        ll ans = (pow_mat({1, 1, 1, 0}, r+2).a - pow_mat({1, 1, 1, 0}, l+1).a + MOD) % MOD;
        cout << ans << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        
    solve();
    
    return 0;
}