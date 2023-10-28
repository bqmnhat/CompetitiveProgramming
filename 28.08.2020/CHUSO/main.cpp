#include <iostream>
#include <bits/stdc++.h>
#include <cstring>
using namespace std;

void BuildA1(string &s) {
    int l = s.length();
    for (int i = l-1; i>=0; i--) {
        s.append(s.substr(i,1));
    }
}

void Solve(string s, int n, int m) {
    int lOfAn = s.length();
    for (int i = 1; i<=n; i++)
        lOfAn = lOfAn * 2;
    BuildA1(s);
    if (m > lOfAn) {
        cout << -1;
        return;
    }
    int l = s.length();
    if (m%l == 0)
        cout << s[0];
    else
        cout << s[m%l - 1];
}

int main()
{
    string s;
    int n,m;
    freopen("CHUSO.INP", "r", stdin);
    freopen("CHUSO.OUT", "w", stdout);
    cin >> s >> n >> m;
    Solve(s,n,m);
    return 0;
}
