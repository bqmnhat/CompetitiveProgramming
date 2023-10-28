#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a[21], x[21], sum[4], s = 0, la = 0;
char d[4] = {' ', 'A', 'B', 'C'};
string ans[4000001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        s += a[i];
    }
}

void StoreAns() {
    if ((sum[1] == sum[2]) && (sum[2] == sum[3])) {
        string tmp = "";
        for (int i=1; i<=n; i++)
            tmp = tmp + d[x[i]];
        ans[++la] = tmp;
    }
}

void Try(int i) {
    for (int j=1; j<=3; j++) {
        if (sum[j] + a[i] <= s/3) {
            x[i] = j;
            sum[j] += a[i];
            if (i == n)
                StoreAns();
            else
                Try(i+1);
            sum[j] -= a[i];
        }
    }
}

void PrintAns() {
    if (la == 0) {
        cout << "-1";
        return;
    }
    cout << la << '\n';
    for (int i=1; i<=la; i++)
        cout << ans[i] << '\n';
}

void Solve() {
    if (s % 3 != 0) {
        cout << "-1";
        return;
    }
    Try(1);
    PrintAns();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("DOWRY.INP", "r", stdin);
    freopen("DOWRY.OUT", "w", stdout);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
