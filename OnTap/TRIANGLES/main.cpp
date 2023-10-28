#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
long long a[1000001];

void MakeTri() {
    a[0] = 1;
    a[1] = 5;
    for (int i=2; i<=1000000; i++) {
        a[i] = (((a[i-1]%1000000007)*3)%1000000007+2)%1000000007;
    }
}

void Solve() {
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        cout << a[x] << '\n';
    }
}

int main()
{
    MakeTri();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TRIANGLES.INP", "r", stdin);
    freopen("TRIANGLES.OUT", "w", stdout);
    cin >> n;
    Solve();
    return 0;
}
