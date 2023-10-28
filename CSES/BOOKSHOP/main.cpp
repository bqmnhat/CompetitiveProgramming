#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
#define MaxX 100000
using namespace std;
int n, x, h[MaxN+5], s[MaxN+5], f[MaxN+5][MaxX+5];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> h[i];
    for (int i=1; i<=n; i++)
        cin >> s[i];
}

int MaxPages() {
    f[1][h[1]] = s[1];
    for (int i=2; i<=n; i++) {
        for (int j=1; j<=x; j++) {
            if (j - h[i]>= 0)
                f[i][j] = max(f[i-1][j], max(f[i-1][j-h[i]] + s[i], f[i][j-1]));
            else
                f[i][j] = max(f[i-1][j], f[i][j-1]);
        }
    }
    return f[n][x];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    ReadData();
    cout << MaxPages();
    return 0;
}
