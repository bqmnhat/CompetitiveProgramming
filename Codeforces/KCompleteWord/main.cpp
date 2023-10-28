#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int t, k, n, gr[MaxN+1][26];
string s;

void InitGrouping() {
    for (int i=1; 2*i<=k+1; i++)
        for (int j=0; j<=25; j++)
            gr[i][j] = 0;
}

void Grouping() {
    InitGrouping();
    for (int i=1; 2*i <= k+1; i++) {
        int j = i;
        while (j <= n) {
            int c = s[j] - 'a';
            gr[i][c]++;
            j += k;
        }
        if ((2*i == k+1) && (k%2))
            continue;
        j = k+1-i;
        while (j <= n) {
            int c = s[j] - 'a';
            gr[i][c]++;
            j += k;
        }
    }
}

int Solution() {
    int ans = 0;
    for (int i=1; 2*i <= k+1; i++) {
        int Sum = 0, Max = 0, cnt = 0;
        for (int j=0; j<=25; j++)
            if (gr[i][j] != 0) {
                cnt++;
                Sum += gr[i][j];
                Max = max(Max, gr[i][j]);
            }
        int MinDif = Sum - Max;
        if (cnt == 1)
            MinDif = 0;
        ans += MinDif;
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> k >> s;
        s = ' ' + s;
        Grouping();
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
