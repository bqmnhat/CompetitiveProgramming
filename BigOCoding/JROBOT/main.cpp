#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m, ValOfst, sx, sy, a[1001][1001];
bool dd[10001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> a[i][j];
            dd[a[i][j]] = true;
        }
    }
}

int MaxJumps() {
    int ans = 0;
    ValOfst = a[sx][sy];
    for (int i=ValOfst+1; i<=10000; i++) {
        if (dd[i])
            ans++;
    }
    return ans;
}

int main()
{
    cin >> n >> m;
    ReadData();
    cin >> sx >> sy;
    cout << MaxJumps();
    return 0;
}
