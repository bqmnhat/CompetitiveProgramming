#include <iostream>
#include <bits/stdc++.h>
#define MaxN 20
using namespace std;
int x[MaxN+1], t, n, Min, Max;

void ReadData() {
    Max = 0;
    Min = 1e9 + 7;
    for (int i=1; i<=n; i++) {
        cin >> x[i];
        Min = min(Min, x[i]);
        Max = max(Max, x[i]);
    }
}

int Solution() {
    return ((Max - Min)*2);
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
