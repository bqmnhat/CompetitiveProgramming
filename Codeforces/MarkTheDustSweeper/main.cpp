#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int t, n, DSt;
ll a[MaxN+1], sum;

void ReadData() {
    DSt = n+1;
    sum = 0;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        if ((a[i] != 0) && (DSt == n+1))
            DSt = i;
        sum += a[i];
    }
    sum = sum - a[n];
}

ll Solution() {
    ll ans = sum;
    for (int i=DSt; i<n; i++)
        if (a[i] == 0)
            ans++;
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
