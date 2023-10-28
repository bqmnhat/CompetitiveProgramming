#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int t, n, a[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

int Solution() {
    int CntOdd = 0, CntEven = 0;
    for (int i=1; i<=n; i++) {
        if (a[i]%2 == 0)
            CntEven++;
        else
            CntOdd++;
    }
    return min(CntEven, CntOdd);
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
