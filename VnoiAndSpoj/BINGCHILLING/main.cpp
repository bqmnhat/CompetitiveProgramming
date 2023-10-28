#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int t, x[MaxN+1], y[MaxN+1], a[MaxN+1];

void ReadData() {
    for (int i=1; i<=t; i++)
        cin >> x[i] >> y[i] >> a[i];
}

void Solve() {
    for (int i=1; i<=t; i++) {
        int NumOfSet = a[i]/(x[i] + y[i]);
        int r = a[i] - NumOfSet*(x[i] + y[i]);
        int Cost = NumOfSet*x[i];
        if (r <= x[i])
            Cost += r;
        else
            Cost += x[i];
        cout << Cost*5 << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    ReadData();
    Solve();
    return 0;
}
