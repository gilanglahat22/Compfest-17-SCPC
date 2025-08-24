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
#define bc __builtin_popcountll
#define tz __builtin_ctzll
#define lz __builtin_clzll
#define sz(v) (int)v.size()
#define ps(y) cout << fixed << setprecision(y)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define trav(x, v) for(auto &x: v)
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define rev(i, a, b) for(int i = a; i >= b; i--)
#define rep0(i, n) rep(i, 0, n - 1)
#define rev0(i, n) rev(i, n - 1, 0)
#define rep1(i, n) rep(i, 1, n)
#define rev1(i, n) rev(i, n, 1)
#define inp(arr, n) rep0(i, n) cin >> arr[i];

int n;
vector<ll> A;
vector<int> L, R, dl, dr;
ll res;
int lmin,lmax,rmin,rmax,st,ed;

void f() {
    stack<int> s;
    rep0(i, n) {
        while (!s.empty() && A[s.top()] < A[i]) s.pop();
        L[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    while (!s.empty()) s.pop();
    rev0(i, n) {
        while (!s.empty() && A[s.top()] <= A[i]) s.pop();
        R[i] = s.empty() ? n : s.top();
        s.push(i);
    }
}

void g() {
    rep0(i, n) {
        if (A[i] == 1) {
            dl[i] = -1;
            dr[i] = n;
            continue;
        }
        dl[i] = -1;
        st = L[i] + 1;
        if (L[i] == -1) st = 0;
        rev(j, i-1, st) {
            if (A[i] % A[j]) {
                dl[i] = j;
                break;
            }
        }
        if (dl[i] == -1) dl[i] = L[i];
        dr[i] = n;
        ed = R[i] - 1;
        if (R[i] == n) ed = n-1;
        rep(j, i+1, ed) {
            if (A[i] % A[j]) {
                dr[i] = j;
                break;
            }
        }
        if (dr[i] == n) dr[i] = R[i];
    }
}

void h() {
    rep0(i, n) {
        lmin = max(L[i] + 1, dl[i] + 1);
        lmax = i;
        rmin = i;
        rmax = min(R[i] - 1, dr[i] - 1);
        if (lmin <= lmax && rmin <= rmax) {
            res += (ll)(lmax - lmin + 1) * (rmax - rmin + 1);
        }
    }
}

void solve(){
    cin >> n;
    A.resize(n);
    inp(A, n);
    L.assign(n, -1);
    R.assign(n, n);
    dl.assign(n, -1);
    dr.assign(n, n);
    res = 0;
    
    f();
    g();
    h();
    
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    solve();
    
    return 0;
}