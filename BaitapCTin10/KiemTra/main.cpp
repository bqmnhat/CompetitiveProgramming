#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,q;
long long a[1000001], cmd;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

int BinSearch(long long val) {
    int lo = 1, hi = n;
    while (lo <= hi) {
        int m = (lo + hi)/2;
        if (a[m] == val)
            return m;
        else if (a[m] < val)
            lo = m + 1;
        else
            hi = m - 1;
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    sort(a+1, a+1+n);
    cin >> q;
    for (int i=1; i<=q; i++) {
        cin >> cmd;
        if (BinSearch(cmd) != -1)
            cout << "YES";
        else
            cout << "NO";
        cout << '\n';
    }
    return 0;
}
