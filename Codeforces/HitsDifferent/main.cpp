#include <iostream>
#include <bits/stdc++.h>
#define MaxN 2025
#define MaxVal 4000000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int t, n;
pii coor[MaxVal+5];
ll a[MaxN+5][MaxN+5], pref[MaxN+5][MaxN+5];

void MakeA() {
    int cnt = 0;
    for (int i=1; i<=MaxN; i++) {
        int x = i, y = 1;
        while (x >= 1) {
            cnt++;
            a[x][y] = cnt;
            coor[cnt] = pii(x, y);
            x--;
            y++;
        }
    }
}

void MakePref() {
    for (int i=1; i<=MaxN; i++)
        for (int j=1; j<=MaxN; j++)
            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + (a[i][j]*a[i][j]);
}

ll SumPref(int x1, int y1, int x2, int y2) {
    return (pref[x2][y2] - pref[x1-1][y2] - pref[x2][y1-1] + pref[x1-1][y1-1]);
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        cout << SumPref(1, 1, coor[n].first, coor[n].second) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    MakeA();
    MakePref();
    Solve();
    return 0;
}
