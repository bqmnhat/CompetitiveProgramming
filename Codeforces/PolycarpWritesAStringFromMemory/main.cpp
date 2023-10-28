#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
#define MaxC 26
using namespace std;
int t;
string s;
bool vis[MaxC+1];

void InitVis() {
    for (int i=0; i<MaxC; i++)
        vis[i] = false;
}

int Solution() {
    int ans = 0, cntdif = 0;
    InitVis();
    int n = s.length();
    for (int i=0; i<n; i++) {
        if (!vis[s[i] - 'a'])
            cntdif++;
        if (cntdif == 4) {
            ans++;
            cntdif = 1;
            InitVis();
        }
        vis[s[i] - 'a'] = true;
    }
    if (cntdif > 0)
        ans++;
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> s;
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
