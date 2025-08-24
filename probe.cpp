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

int n;
ll D, K;

int nxt(int s) {
    int p = s / 2 + 1;
    int d = s % 2;
    if (d == 0) {
        if (p < n) return s + 2;
        else return s + 1;
    } else {
        if (p > 1) return s - 2;
        else return s - 1;
    }
}

vector<vector<ll>> mat_mult(const vector<vector<ll>> &A, const vector<vector<ll>> &B) {
    int sz = A.size();
    vector<vector<ll>> C(sz, vector<ll>(sz, 0));
    rep0(i, sz) rep0(k, sz) if (A[i][k]) 
        rep0(j, sz) C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

vector<vector<ll>> mat_pow(vector<vector<ll>> M, ll p) {
    int sz = M.size();
    vector<vector<ll>> res(sz, vector<ll>(sz, 0));
    rep0(i, sz) res[i][i] = 1;
    while (p) {
        if (p & 1) res = mat_mult(res, M);
        M = mat_mult(M, M);
        p >>= 1;
    }
    return res;
}

void solve() {
    cin >> n >> D >> K;
    int states = 2 * n;
    vector<vector<ll>> M(states, vector<ll>(states, 0));
    
    rep0(s, states) {
        vector<int> seq;
        map<int, int> seen;
        int cur = s;
        while (seen.find(cur) == seen.end()) {
            seen[cur] = sz(seq);
            seq.pb(cur);
            cur = nxt(cur);
        }
        int T0 = seen[cur];
        int L = sz(seq);
        int C = L - T0;
        
        vector<ll> cnt(states, 0);
        int lim = min((ll)L - 1, D);
        rep1(k, lim) cnt[seq[k]]++;
        
        if (D >= L) {
            ll R = D - L + 1;
            ll full = R / C;
            ll rem = R % C;
            vector<ll> cycle_cnt(C, full);
            rep0(i, rem) cycle_cnt[i]++;
            rep0(i, C) cnt[seq[T0 + i]] = (cnt[seq[T0 + i]] + cycle_cnt[i]) % MOD;
        }
        
        rep0(t, states) M[t][s] = cnt[t];
    }
    
    auto M_exp = mat_pow(M, K);
    vector<ll> v0(states, 0);
    v0[0] = 1;
    vector<ll> v_fin(states, 0);
    rep0(i, states) rep0(j, states) 
        v_fin[i] = (v_fin[i] + M_exp[i][j] * v0[j]) % MOD;
    
    ll ans = 0;
    rep0(s, states) {
        int p = s / 2 + 1;
        ans = (ans + p * v_fin[s]) % MOD;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}