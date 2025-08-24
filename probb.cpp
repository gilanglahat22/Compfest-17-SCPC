#include <iostream>
#include <vector>
using namespace std;

const int MAX = 200000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<long long> avail(MAX, 0);
    for (int i = 0; i < n; i++) {
        int a;
        long long b;
        cin >> a >> b;
        if (a < MAX) {
            avail[a] = b;
        }
    }
    
    if (avail[0] % 2 != 0) {
        cout << "TIDAK" << endl;
        return 0;
    }
    
    vector<long long> arr = avail;
    
    for (int i = 0; i < MAX-1; i++) {
        long long carry = arr[i] / 2;
        arr[i] %= 2;
        arr[i+1] += carry;
    }
    
    long long carry2 = 0;
    for (int i = 0; i < MAX-1; i++) {
        long long current = avail[i] + carry2;
        if (arr[i+1] == 1) {
            if (current < 1) {
                cout << "TIDAK" << endl;
                return 0;
            }
            current--;
        }
        carry2 = current / 2;
    }
    
    cout << "YA" << endl;
    return 0;
}