#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int q,n;
long long a[200001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void Solve() {
    int i = n;
    while ((i > 1) && (a[i-1] >= a[i]))
        i--;
    while ((i > 1) && (a[i-1] <= a[i]))
        i--;
    cout << (i-1) << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> q;
    for (int i=1; i<=q; i++) {
        cin >> n;
        ReadData();
        Solve();
    }
    return 0;
}
