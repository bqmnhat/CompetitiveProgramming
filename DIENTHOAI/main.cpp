#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, h[100001], c, Max = 0, f[100001][101], inf = 1e9;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> h[i];
        Max = max(Max, h[i]);
    }
}

int Solution() {
    int MinAns = 1e9;
    for (int i=1; i<=100000; i++)
        for (int j=0; j<=100; j++)
            f[i][j] = inf;
    for (int j=h[1]; j<=Max; j++)
        f[1][j] = (j - h[1])*(j - h[1]);
    for (int i=2; i<=n; i++) {
        for (int j=h[i]; j<=Max; j++) {
            for (int t = h[i-1]; t<=Max; t++) {
                int Fee = abs(j - t)*c + (j - h[i])*(j - h[i]);
                f[i][j] = min(f[i][j], f[i-1][t] + Fee);
            }
        }
    }
    for (int j = h[n]; j<=Max; j++)
        MinAns = min(MinAns, f[n][j]);
    return MinAns;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> c;
    ReadData();
    cout << Solution();
    return 0;
}
