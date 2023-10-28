#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000
using namespace std;
int m, n, h[MaxN+1], a[MaxN+1][MaxN+1], l[MaxN+1], r[MaxN+1];

void ReadData() {
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            cin >> a[i][j];
}

int Solution() {
    int ans = 0;
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            if (a[i][j] == 1)
                h[j]++;
            else
                h[j] = 0;
        }
        for (int j=1; j<=n; j++) {
            int tmp = j-1;
            while ((tmp > 0) && (h[tmp] >= h[j]))
                tmp = l[tmp];
            l[j] = tmp;
        }
        for (int j=n; j>=1; j--) {
            int tmp = j+1;
            while ((tmp <= n) && (h[tmp] >= h[j]))
                tmp = r[tmp];
            r[j] = tmp;
            ans = max(ans, h[j]*(r[j] - l[j]-1));
        }
    }
    return ans;
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
