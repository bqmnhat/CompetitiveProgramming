#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, BASE = 2e6, a[2001], tk[4000002];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

long long Solution() {
    long long ans = 0;
    for (int i=1; i<=n; i++)
        for (int j=i+1; j<=n; j++)
            tk[a[i] + a[j] + BASE]++;
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++)
            tk[a[i]+a[j] + BASE]--;
        for (int j = 1; j< i; j++)
            ans += (long long)tk[-(a[i] + a[j]) + BASE];
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("ZEROQUAD.INP", "r", stdin);
    freopen("ZEROQUAD.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
