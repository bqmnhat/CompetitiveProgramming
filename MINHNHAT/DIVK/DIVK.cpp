#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[1000000], e[1000000], n, k;

void ReadData(int a[], int n) {
    for (int i = 1; i<=n; i++) {
        cin >> a[i];
    }
}

void Solve() {
    int t = 0,tk,tmp = 0,d = 0;
    e[0] = 0;
    for (int i = 1; i<=n; i++) {
        t = t + a[i];
    }
    if (t%k == 0)
        tk = t/k;
    else {
        cout << "NO";
        return;
    }
    for (int i = 1; i<=n; i++) {
        tmp = tmp + a[i];
        if (tmp == tk) {
            tmp = 0;
            d = d + 1;
            e[d] = i;
        }
    }
    if (d == k) {
        for (int i = 1; i<=k; i++) {
            for (int j = e[i-1]+1; j<=e[i]; j++)
                cout << a[j] << " ";
            cout << endl;
        }
    }
    else
        cout << "NO";
}

int main()
{
    freopen("DIVK.INP", "r", stdin);
    freopen("DIVK.OUT", "w", stdout);
    cin >> n >> k;
    ReadData(a,n);
    Solve();
    return 0;
}
