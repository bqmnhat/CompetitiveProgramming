#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int v[21],a[81][21], m,n;

void ReadData() {
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }
}

int Solution() {
    int ans = 0, i = 1, tmp = 0, cost = 0;;
    while (true) {
        if (i>n) {
            if (tmp>ans)
                ans = tmp;
            i--;
        }
        if (i < 0)
            return ans;
        if ((cost+1 <= m) &&  (i<=m)) {
            cost += 1;
            tmp = tmp - a[v[i]][i] + a[v[i]+1][i];
            v[i]++;
            i++;
            //i++;
        }
        else {
            if (tmp>ans)
                ans = tmp;
            cost = cost - v[i];
            tmp = tmp - a[v[i]][i];
            v[i] = 0;
            i--;
        }
    }
}

int main()
{
    freopen("INVEST.INP", "r", stdin);
    freopen("INVEST.OUT", "w", stdout);
    cin >> m >> n;
    ReadData();
    cout << Solution();
    return 0;
}
