#include <iostream>
#include <bits/stdc++.h>
#define MaxN 50
using namespace std;
int t, n, a[MaxN+5];

void ReadData() {
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

void Solve() {
    bool IsPerfect = true;
    for (int i = 2; i <= n; i++)
        if ((abs(a[i] - a[i - 1]) != 5) && (abs(a[i] - a[i - 1]) != 7))
            IsPerfect = false;
    if (IsPerfect)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        ReadData();
        Solve();
    }
    return 0;
}
