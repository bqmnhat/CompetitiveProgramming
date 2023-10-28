#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, TVRow[100], a[100], lt = 0;

void Solve() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++)
            cin >> a[j];
        sort(a+1, a+1+n);
        lt++;
        TVRow[lt] = a[((n-1)/2) + 1];
    }
    sort(TVRow + 1, TVRow + 1 + lt);
    cout << TVRow[((lt-1)/2) + 1];
}

int main()
{
    cin >> n;
    Solve();
    return 0;
}
