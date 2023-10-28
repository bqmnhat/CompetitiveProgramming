#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[10000001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

void Solve() {
    sort(a+1, a+1+n, greater<ll>());
    cout << a[1] << " " << a[2] << " " << a[3];
}

int main()
{
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
