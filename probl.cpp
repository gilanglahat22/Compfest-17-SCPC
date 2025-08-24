#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M = 998244353;

#define f first
#define s second
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
#define tr(x, v) for(auto &x: v)
#define w(t) int t; cin >> t; while(t--)
#define rep(i, a, b) for(int i = a; i <= b; i++)
#define rev(i, a, b) for(int i = a; i >= b; i--)
#define rep0(i, n) rep(i, 0, n - 1)
#define rev0(i, n) rev(i, n - 1, 0)
#define rep1(i, n) rep(i, 1, n)
#define rev1(i, n) rev(i, n, 1)
#define in(a, n) rep0(i, n) cin >> a[i];

int n, q;
vector<vector<pair<int, int>>> g;
vector<tuple<int, int, int>> e;
vector<int> inT, outT, xv, p;
vector<int> nxt, dfsO;
int tmR = 0;
vector<int> ec, ew;

struct ST {
    int n;
    vector<int> lz;
    vector<vector<int>> ct;
    vector<int> s;
    
    void cmb(int i) {
        int l = 2*i+1, r = 2*i+2;
        s[i] = s[l] + s[r];
        rep0(bit, 30) ct[i][bit] = ct[l][bit] + ct[r][bit];
    }
    
    void ap(int i, int d) {
        lz[i] ^= d;
        rep0(bit, 30) if(d>>bit&1) ct[i][bit] = s[i] - ct[i][bit];
    }
    
    void psh(int i) {
        if(lz[i]) {
            ap(2*i+1, lz[i]);
            ap(2*i+2, lz[i]);
            lz[i] = 0;
        }
    }
    
    ST(vector<int>& base) {
        n = sz(base);
        lz.assign(4*n, 0);
        ct.assign(4*n, vector<int>(30, 0));
        s.assign(4*n, 0);
        bld(0, 0, n-1, base);
    }
    
    void bld(int i, int l, int r, vector<int>& base) {
        if(l == r) {
            s[i] = 1;
            rep0(bit, 30) ct[i][bit] = (base[l]>>bit)&1;
            return;
        }
        int m = (l+r)>>1;
        bld(2*i+1, l, m, base);
        bld(2*i+2, m+1, r, base);
        cmb(i);
    }
    
    void upd(int l, int r, int d, int i=0, int L=0, int R=-1) {
        if(R == -1) R = n-1;
        if(l > R || r < L) return;
        if(l <= L && R <= r) return ap(i, d), void();
        psh(i);
        int m = (L+R)>>1;
        upd(l, r, d, 2*i+1, L, m);
        upd(l, r, d, 2*i+2, m+1, R);
        cmb(i);
    }
    
    void qry(int l, int r, vector<int>& res, int i=0, int L=0, int R=-1) {
        if(R == -1) R = n-1;
        if(l > R || r < L) return;
        if(l <= L && R <= r) {
            rep0(bit, 30) res[bit] += ct[i][bit];
            return;
        }
        psh(i);
        int m = (L+R)>>1;
        qry(l, r, res, 2*i+1, L, m);
        qry(l, r, res, 2*i+2, m+1, R);
    }
};

void solve() {
    cin >> n;
    g.resize(n+1);
    e.resize(n-1);
    rep0(i, n-1) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].eb(v, w);
        g[v].eb(u, w);
        e[i] = {u, v, w};
    }
    
    inT.assign(n+1, -1);
    outT.assign(n+1, -1);
    xv.assign(n+1, 0);
    p.assign(n+1, 0);
    nxt.assign(n+1, 0);
    stack<int> st;
    st.push(1);
    p[1] = 0;
    xv[1] = 0;
    while(!st.empty()) {
        int u = st.top();
        if(inT[u] == -1) {
            inT[u] = tmR++;
            dfsO.pb(u);
        }
        if(nxt[u] < sz(g[u])) {
            int v = g[u][nxt[u]].f;
            int w = g[u][nxt[u]].s;
            nxt[u]++;
            if(v == p[u]) continue;
            p[v] = u;
            xv[v] = xv[u] ^ w;
            st.push(v);
        } else {
            outT[u] = tmR-1;
            st.pop();
        }
    }
    
    ec.resize(n-1);
    ew.resize(n-1);
    rep0(i, n-1) {
        int u = get<0>(e[i]), v = get<1>(e[i]), w = get<2>(e[i]);
        if(p[v] == u) ec[i] = v;
        else ec[i] = u;
        ew[i] = w;
    }
    
    vector<int> b(n);
    rep0(i, n) b[i] = xv[dfsO[i]];
    ST seg(b);
    vector<int> gc(30, 0);
    vector<int> tmp(30, 0);
    seg.qry(0, n-1, tmp);
    rep0(bit, 30) gc[bit] = tmp[bit];
    
    cin >> q;
    while(q--) {
        int x, y;
        cin >> x >> y;
        x--;
        int ow = ew[x], nw = y;
        int D = ow ^ nw;
        int v = ec[x];
        int l = inT[v], r = outT[v];
        int siz = r - l + 1;
        
        vector<int> sc(30, 0);
        seg.qry(l, r, sc);
        seg.upd(l, r, D);
        
        rep0(bit, 30) if(D>>bit&1) gc[bit] = gc[bit] - sc[bit] + (siz - sc[bit]);
        ew[x] = nw;
        
        ll res = 0;
        rep0(bit, 30) {
            ll cnt = gc[bit];
            ll prs = cnt * (n - cnt);
            res = (res + (1LL<<bit)*prs) % M;
        }
        cout << res << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    solve();
    
    return 0;
}