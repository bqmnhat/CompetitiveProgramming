#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
int n, k, a[MaxN+5][MaxN+5], pref[MaxN+5][MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            cin >> a[i][j];
}

void MakePref() {
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            pref[i][j] = pref[i][j-1] + pref[i-1][j] - pref[i-1][j-1] + a[i][j];
}

int SumOfRec(int x1, int y1, int x2, int y2) {
    return pref[x2][y2] - pref[x1-1][y2] - pref[x2][y1-1] + pref[x1-1][y1-1];
}

int Solution() {
    int ans = 0;
    for (int i=k; i<=n; i++)
        for (int j=k; j<=n; j++)
            ans = max(ans, SumOfRec(i-k+1, j-k+1, i, j));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ReadData();
    MakePref();
    cout << Solution();
    return 0;
}
