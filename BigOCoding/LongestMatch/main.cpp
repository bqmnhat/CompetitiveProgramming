#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s, t;
map<string, int> m;
int cnt, a[1001], b[1001], dp[1001][1001];

bool IsChar(char c) {
    return (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')));
}

void SplitAndMap(string s) {
    s = s + " ";
    int l = s.length();
    string tmp = "";
    for (int i=0; i<l; i++) {
        if (IsChar(s[i]))
            tmp = tmp + s[i];
        else {
            if (tmp == "")
                continue;
            if (m.find(tmp) == m.end()) {
                cnt++;
                m[tmp] = cnt;
            }
            tmp = "";
        }
    }
}

void Encode(string s, int a[], int& la) {
    s = s + " ";
    int ls = s.length();
    la = 0;
    string tmp = "";
    for (int i=0; i<ls; i++) {
        if (IsChar(s[i]))
            tmp = tmp + s[i];
        else {
            if (tmp == "")
                continue;
            la++;
            a[la] = m[tmp];
            tmp = "";
        }
    }
}

int Solution() {
    m.clear();
    SplitAndMap(s);
    SplitAndMap(t);
    int la = 0, lb = 0;
    Encode(s, a, la);
    Encode(t, b, lb);
    memset(dp, 0, sizeof(dp));
    for (int i=1; i<=la; i++) {
        for (int j=1; j<=lb; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
        }
    }
    return dp[la][lb];
}

void Solve() {
    int cnt = 0;
    while ((getline(cin, s)) && (getline(cin, t))) {
        cnt++;
        cout << cnt << ". ";
        if ((t.length() == 0) || (s.length() == 0)) {
            cout << "Blank!\n";
            continue;
        }
        cout << "Length of longest match: " << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}
