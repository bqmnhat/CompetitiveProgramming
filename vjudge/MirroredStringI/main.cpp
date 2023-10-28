#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t;
string s;

bool IsPalin(string& s) {
    int i = 0, j = s.length()-1;
    while (i <= j) {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

bool IsMirrored(string& s) {
    int l = s.length();
    for (int i=0; i<l; i++)
        if ((s[i] != 'A') && (s[i] != 'H') && (s[i] != 'I') && (s[i] != 'M') && (s[i] != 'O') && (s[i] != 'T') && (s[i] != 'U') && (s[i] != 'V') && (s[i] != 'W') && (s[i] != 'X') && (s[i] != 'Y'))
            return false;
    return IsPalin(s);
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> s;
        if (IsMirrored(s))
            cout << "yes\n";
        else
            cout << "no\n";
    }
}
//
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
