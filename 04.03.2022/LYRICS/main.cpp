#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m;
string s[1001];

void ReadData() {
    cin.ignore();
    for (int i=1; i<=n; i++)
        getline(cin, s[i]);
}

int FindKBetween(string a, string b) {
    int la = a.length(), lb = b.length(), ans = 0;
    int i = la-1, j = lb-1;
    while ((i >= 0) && (j >= 0) && (a[i] == b[j])) {
        ans++;
        i--;
        j--;
    }
    return ans;
}

int Solution() {
    int K = s[1].length();
    for (int i=1; i<=m; i++) {
        K = min(K, (int)s[i].length());
        for (int j = 1; i+j*m <= n; j++)
            K = min(K, FindKBetween(s[i], s[i+j*m]));
    }
    return K;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("LYRICS.INP", "r", stdin);
    freopen("LYRICS.OUT", "w", stdout);
    cin >> n >> m;
    ReadData();
    cout << Solution();
    return 0;
}
