#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long a[100001], n ,s[100001], k;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

void Solve() {
    for (int i=1; i<= n; i++) {
        s[i] = s[i-1] + a[i];
        if (s[i] == k) {
            cout << 1 << " " << i;
            return;
        }
    }
    for (int i=2; i<=n-1; i++) {
        for (int j=i+1; j<=n; j++) {
            if (s[j]- s[i-1] == k) {
                cout << i << " " << j-i+1;
                return;
            }
        }
    }
    cout << "NO";
}

int main()
{
    freopen("SUM_S.INP", "r", stdin);
    freopen("SUM_S.OUT", "w", stdout);
    cin >> n >> k;
    ReadData();
    Solve();
}
