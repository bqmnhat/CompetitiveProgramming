#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
ll Left[3001], Right[3001], a[3001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

ll Solution() {
    ll ans = 0;
    for (int j=1; j<=n; j++) {
        for (int i=1; i<=n; i++)
            Right[i] = 0;
        for (int k=n; k>=j+1; k--) {
            ans += (Left[a[k]]*Right[a[j]]);
            Right[a[k]]++;
        }
        Left[a[j]]++;
    }
    for (int i=1; i<=n; i++)
        Left[i] = Right[i] = 0;
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        cout << Solution() << '\n';
    }
}

int main()
{
    cin >> t;
    Solve();
    return 0;
}
