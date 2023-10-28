#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string a[100001];
int n;

void ReadData() {
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

bool StrCmp(string a, string b) {
    string s1 = a+b, s2 = b+a;
    return (s1>s2);
}

void Solve() {
    sort(a+1,a+1+n, StrCmp);
    for (int i = 1; i<=n; i++) {
        cout << a[i];
    }
}

int main()
{
    freopen("MAXNUM.INP", "r", stdin);
    freopen("MAXNUM.OUT", "w", stdout);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
