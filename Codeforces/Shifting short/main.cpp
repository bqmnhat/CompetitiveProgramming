#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a[51], top = 1, l[51], r[51], d[51], ll=0, t;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

void Update(int x, int top) {
    int tmp = a[x];
    for (int i = x; i>top; i--)
        a[i] = a[i-1];
    a[top] = tmp;
}

void PrintAns(int k) {
    for (int i=1; i<=k; i++) {
        cout << l[i] << " " << r[i] << " " << d[i] << '\n';
    }
}

void Solve() {
    int ans = 0;
    while (top <= n) {
        int Min = 1e9 + 1, MinId = 0;
        for (int i=top; i<=n; i++) {
            if (a[i] < Min) {
                Min = a[i];
                MinId = i;
            }
        }
        if (MinId != top) {
            ans++;
            ll++;
            l[ll] = top;
            r[ll] = MinId;
            d[ll] = MinId - top;
            Update(MinId,top);
        }
        top  = top + 1;
    }
    cout << ans << '\n';
    PrintAns(ll);
}

int main()
{
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        ll = 0;
        top = 1;
        Solve();
    }
    return 0;
}
