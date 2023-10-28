#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, b[25];
long long pow2[25], Sum, Tmp, a[97], dp[97][192001];

void InitDP() {
    for (int i=0; i<=96; i++)
        for (int j=0; j<=192000; j++)
            dp[i][j] = 0;
}

void InitB() {
    for (int i=0; i<=24; i++)
        b[i] = 0;
}

void MakePow2() {
    pow2[0] = 1;
    for (int i=1; i<=24; i++) {
        pow2[i] = pow2[i-1]*2;
    }
}

void ReadData() {
    for (int i=0; i<n; i++) {
        cin >> a[i];
        Sum += a[i];
    }
}

void Next(int n)
{
	int i = 0;
	while ((b[i] != 0) && (i <= n)) {
        b[i] = 0;
        Tmp = Tmp - a[i];
        ++i;
    }
	b[i] = 1;
	Tmp = Tmp + a[i];
}

long long Solution1(long long p0, long long p1, int pos)
{
    if (pos == n) {
        if (p0 == p1)
            return p0;
        else
            return 0;
    }
    long long ans = Solution1(p0, p1, pos + 1);
    ans = max(ans, Solution1(p0 + a[pos], p1, pos + 1));
    ans = max(ans,Solution1(p0, p1 + a[pos], pos + 1));
    return ans;
}

long long Solution2() {
    long long MinNum = -1e9, limit = 2*Sum+1;
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < limit; j++)
            dp[i][j] = MinNum;
    }
    dp[0][Sum] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < limit; j++) {
            if ((j - a[i - 1]) >= 0 && dp[i - 1][j - a[i - 1]] != MinNum)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i - 1]] + a[i - 1]);
            if ((j + a[i - 1]) < limit && dp[i - 1][j + a[i - 1]] != MinNum)
                dp[i][j] = max(dp[i][j], dp[i - 1][j + a[i - 1]]);
            if (dp[i - 1][j] != MinNum)
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
    long long ans = abs(dp[n][Sum] - (Sum - dp[n][Sum]));
    return ans;
}

void Solve() {
    while (cin >> n) {
        Sum = 0;
        Tmp = 0;
        ReadData();
        if (n <= 24) {
            InitB();
            long long t = Solution1(0,0,0);
            cout << abs(t - (Sum - t));
        }
        else {
            InitDP();
            cout << Solution2();
        }
        cout << '\n';
    }
}

int main()
{
    freopen("KHOBAU2.INP", "r", stdin);
    freopen("KHOBAU2.OUT", "w", stdout);
    MakePow2();
    Solve();
    return 0;
}
