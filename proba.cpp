#include <bits/stdc++.h>
using namespace std;

long long a,b,n;
long long sum;
void solve(){
    if(sum==0) cout << "Mabar\n";
    else if(sum > 0) cout << "Pak Chanek\n";
    else cout << "Pak Ganesh\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for(long long i = 0; i<n; i++){
        cin >> a;
        sum += a;
    }
    for(long long i = 0; i<n; i++){
        cin >> b;
        sum -= b;
    }
    solve();
    
    return 0;
}