#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s, v;

void PrintStr(string sx) {
    for (int i=0; i<sx.length(); i++) {
        if (sx[i] != ' ')
            cout << sx[i];
        else
            cout << '#';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SPACING.INP", "r", stdin);
    freopen("SPACING.OUT", "w", stdout);
    getline(cin, s);
    getline(cin, v);
    PrintStr(s);
    return 0;
}
