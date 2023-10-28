#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;

void Solve() {
    for (int i=0; i<s.length(); i++) {
        if (s[i] < 'a') {
            s[i] = s[i] + 32;
        }
        if ((s[i] == 'a') or (s[i] == 'e') or (s[i] == 'u') or (s[i] == 'o') or (s[i] == 'i') or (s[i] == 'y')) {
            s[i] = '-';
        }
    }
    if (s[0] != '-')
        cout << '.';
    for (int i=0; i<s.length(); i++) {
        if (s[i] != '-') {
            cout << s[i];
        }
        if ((s[i+1] != '-') && (i + 1 < s.length())) {
            cout << '.';
        }
    }
}

int main()
{
    freopen("CHANGE.INP", "r", stdin);
    freopen("CHANGE.OUT", "w", stdout);
    cin >> s;
    Solve();
    return 0;
}

