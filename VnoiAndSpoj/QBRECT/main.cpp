#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
typedef long long ll;
int m, n, a[MaxN+5][MaxN+5], r[MaxN+5], l[MaxN+5];
ll dpCol[MaxN+5][MaxN+5];

void ReadData() {
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            cin >> a[i][j];
}

ll Solution() {
    ll res = 0;
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            if (a[i][j] == 0)
                continue;
            if ((i == 1) || (a[i][j] != a[i-1][j]))
                dpCol[i][j] = 1;
            else
                dpCol[i][j] = dpCol[i-1][j] + 1LL;
        }
        vector<int> stk;
        stk.clear();
        for (int j=n; j>=1; j--) {
            while ((!stk.empty()) && (dpCol[i][stk.back()] >= dpCol[i][j]))
                stk.pop_back();
            if (stk.empty())
                r[j] = n;
            else
                r[j] = stk.back() - 1;
            stk.push_back(j);
        }
        stk.clear();
        for (int j=1; j<=n; j++) {
            while ((!stk.empty()) && (dpCol[i][stk.back()] >= dpCol[i][j]))
                stk.pop_back();
            if (stk.empty())
                l[j] = 1;
            else
                l[j] = stk.back() + 1;
            res = max(res, (r[j] - l[j] + 1LL)*dpCol[i][j]);
            stk.push_back(j);
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    ReadData();
    cout << Solution();
    return 0;
}
