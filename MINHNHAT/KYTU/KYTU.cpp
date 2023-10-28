#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;
int a[28];

string LowCase(string s) {
    int l = s.length();
    for (int i=0; i<l; i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

void Solve() {
    int l = s.length();
    s = LowCase(s);
    for (int i = 0; i<l; i++) {
        a[s[i]-96]++;
    }
    int MaxChar = a[1];
    for (int i = 1; i<=27; i++) {
        if (a[i] > MaxChar)
            MaxChar = a[i];
    }
    for (int i = 1; i<=27; i++) {
        if (a[i] == MaxChar) {
            cout << char(i+96);
        }
    }
}

int main()
{
    freopen("KYTU.INP", "r", stdin);
    freopen("KYTU.OUT", "w", stdout);
    cin >> s;
    Solve();
    return 0;
}
