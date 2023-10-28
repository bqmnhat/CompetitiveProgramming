#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
int n, q, a[MaxN+1][MaxN+1], pref[MaxN+1][MaxN+1];
string s[MaxN];

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> s[i];
}

void MakeA() {
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if (s[i][j] == '*')
                a[i+1][j+1] = 1;
}

void MakePref() {
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            pref[i][j] = pref[i-1][j] + pref[i][j-1] + a[i][j] - pref[i-1][j-1];
}

int SumQuery(int x1, int y1, int x2, int y2) {
    return (pref[x2][y2] - pref[x1-1][y2] - pref[x2][y1 - 1] + pref[x1-1][y1-1]);
}

void Solve() {
    MakeA();
    MakePref();
    for (int i=1; i<=q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << SumQuery(x1, y1, x2, y2) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    ReadData();
    Solve();
    return 0;
}
