#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
string s;

void Solve() {
    s = ' ' + s;
    int l = s.length();
    for (int i=0; i<l; i++) {
        if (s[i] == ' ')
            continue;
        if (s[i-1] == ' ')
            cout << char(toupper(s[i]));
        else
            cout << s[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    getline(cin, s);
    Solve();
    return 0;
}
