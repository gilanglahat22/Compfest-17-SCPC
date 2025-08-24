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
#define w(t) int t; cin >> t; while(t--)
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define rrep(i, a, b) for(int i = a; i >= b; i--)
#define rep0(i, n) rep(i, 0, n - 1)
#define rrep0(i, n) rrep(i, n - 1, 0)
#define rep1(i, n) rep(i, 1, n)
#define rrep1(i, n) rrep(i, n, 1)
#define inp(arr, n) rep0(i, n) cin >> arr[i];

struct RTrain { int u, v, a; };
struct LTrain { int u, v; };

class Fenw {
public:
    int n;
    vector<int> tree;
    Fenw(int n) : n(n), tree(n+1, 0) {}
    void upd(int idx, int d) {
        for (; idx <= n; idx += idx & -idx) tree[idx] += d;
    }
    int qry(int idx) {
        int s = 0;
        for (; idx>0; idx -= idx & -idx) s += tree[idx];
        return s;
    }
    int range_qry(int l, int r) {
        return l > r ? 0 : qry(r) - qry(l-1);
    }
};

ll procGrp(vector<RTrain>& R, vector<LTrain>& L) {
    if (R.empty() || L.empty()) return 0;

    sort(all(R), [](RTrain a, RTrain b) { return a.a > b.a; });
    sort(all(L), [](LTrain a, LTrain b) { return a.u > b.u; });

    vector<int> comp;
    trav(r, R) comp.pb(r.u);
    sort(all(comp));
    comp.erase(unique(all(comp)), comp.end());
    int m = sz(comp);
    Fenw fenw(m);

    int ptr = 0;
    ll cnt = 0;
    trav(j, L) {
        int uj = j.u, vj = j.v;
        int low = max(1, 2*vj - uj), high = uj - 1;
        if (low > high) continue;

        while (ptr < sz(R) && R[ptr].a >= uj) {
            int u_val = R[ptr].u;
            int idx = lb(all(comp), u_val) - comp.begin();
            fenw.upd(idx+1, 1);
            ptr++;
        }

        int l_idx = lb(all(comp), low) - comp.begin();
        auto it = ub(all(comp), high);
        int r_idx = it - comp.begin() - 1;
        if (l_idx > r_idx) continue;
        cnt += fenw.range_qry(l_idx+1, r_idx+1);
    }
    return cnt;
}

int n;
map<int, int> same;
ll same_cnt;
vector<RTrain> R;
vector<LTrain> L;
vector<RTrain> Re, Ro;
vector<LTrain> Le, Lo;
void solve() {
    cin >> n;
    vector<pair<int, int>> tr(n);
    rep0(i, n) {
        cin >> tr[i].ff >> tr[i].ss;
        same[tr[i].ff]++;
    }

    same_cnt = 0;
    trav(x, same) same_cnt += (ll)x.ss * (x.ss-1) / 2;

    trav(t, tr) {
        int u = t.ff, v = t.ss;
        if (u < v) R.pb({u, v, 2*v - u});
        else if (u > v) L.pb({u, v});
    }

    trav(r, R) (r.u % 2 == 0 ? Re : Ro).pb(r);
    trav(l, L) (l.u % 2 == 0 ? Le : Lo).pb(l);

    ll opp_cnt = procGrp(Re, Le) + procGrp(Ro, Lo);
    cout << same_cnt + opp_cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    solve();
    
    return 0;
}