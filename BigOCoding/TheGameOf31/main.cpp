#include <iostream>
#include <bits/stdc++.h>
#define MaxN 31
#define MaxCard 4
using namespace std;
int dp[MaxN+1][MaxCard+1][MaxCard+1][MaxCard+1][MaxCard+1][MaxCard+1][MaxCard+1];
string s;

int CalDp(int r, int cnt[7]) {
    if (r == 0)
        return 0;
    if (dp[r][cnt[1]][cnt[2]][cnt[3]][cnt[4]][cnt[5]][cnt[6]] != -1)
        return dp[r][cnt[1]][cnt[2]][cnt[3]][cnt[4]][cnt[5]][cnt[6]];
    for (int i=1; i<=6; i++) {
        if (cnt[i] <= 0)
            continue;
        cnt[i]--;
        if ((r - i >= 0) && (CalDp(r - i, cnt) == 0)) {
            cnt[i]++;
            return dp[r][cnt[1]][cnt[2]][cnt[3]][cnt[4]][cnt[5]][cnt[6]] = 1;
        }
        cnt[i]++;
    }
    return dp[r][cnt[1]][cnt[2]][cnt[3]][cnt[4]][cnt[5]][cnt[6]] = 0;
}

void SolveTestCase() {
    int cnt[7];
    memset(cnt, 0, sizeof(cnt));
    int l = s.length(), sum = 31, CurPlayer = 0; // CurPlayer = 1 => A, = 2 => B
    for (int i=0; i<l; i++) {
        cnt[s[i] - '0']++;
        sum -= (s[i] - '0');
    }
    for (int i=1; i<=6; i++)
        cnt[i] = 4 - cnt[i];
    if (l&1)
        CurPlayer = 2;
    else
        CurPlayer = 1;
    memset(dp, -1, sizeof(dp));
    int ans = CalDp(sum, cnt);
    cout << s << ' ';
    if (ans == 0) {
        if (CurPlayer == 1)
            cout << "B\n";
        else
            cout << "A\n";
    }
    else {
        if (CurPlayer == 1)
            cout << "A\n";
        else
            cout << "B\n";
    }
}

void Solve() {
    while (getline(cin, s))
        SolveTestCase();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
