#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
ll a[MaxN+1];
int t, n, k;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

int Solution() {
    if (k == 1) {
        if (n%2 == 0)
            return ((n-1)/2);
        else
            return (n/2);
    }
    int ans = 0;
    for (int i=2; i<n; i++)
        if (a[i] > a[i-1] + a[i+1])
            ans++;
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> k;
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
