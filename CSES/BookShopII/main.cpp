#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
#define MaxN2 2000
#define MaxPrice 100000
using namespace std;
struct {
    int h, s, k;
} a[MaxN+1], a2[MaxN2+1];
int n, x, dp[MaxN2+1][MaxPrice], n2 = 0;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i].h;
    for (int i=1; i<=n; i++)
        cin >> a[i].s;
    for (int i=1; i<=n; i++)
        cin >> a[i].k;
}

void MakeA2() {
    for (int i=1; i<=n; i++) {
        vector<int> tmp;
        tmp.clear();
        int tmpval = a[i].k, j = 1;
        while (tmpval - j > 0) {
            tmpval -= j;
            n2++;
            a2[n2].k = j;
            a2[n2].h = a[i].h;
            a2[n2].s = a[i].s;
            j *= 2;
        }
        if (tmpval > 0) {
            n2++;
            a2[n2].k = tmpval;
            a2[n2].h = a[i].h;
            a2[n2].s = a[i].s;
        }
    }
}

int Solution() {
    int ans = 0;
    for (int i=1; i<=n2; i++) {
        for (int j = 0; j<=x; j++) {
            dp[i][j] = dp[i-1][j];
            if (j - a2[i].k*a2[i].h >= 0)
                dp[i][j] = max(dp[i][j], dp[i-1][j - a2[i].k*a2[i].h] + a2[i].k*a2[i].s);
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    ReadData();
    MakeA2();
    cout << Solution();
    return 0;
}
