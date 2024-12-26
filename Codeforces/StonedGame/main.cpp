#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
using namespace std;
int t, n, a[MaxN+5], Max = 0, Sum = 0;

void ReadData() {
    Max = Sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        Max = max(Max, a[i]);
        Sum += a[i];
    }
}

void Solve() {
    bool MoreThanHalf = false;
    for (int i = 1; i<=n; i++) {
        if (a[i] > (Sum >> 1)) {
            MoreThanHalf = true;
            break;
        }
    }
    if (MoreThanHalf) {
        cout << "T\n";
        return;
    }
    if (Sum % 2 == 0) {
        cout << "HL\n";
        return;
    }
    cout << "T\n";
    return;
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
