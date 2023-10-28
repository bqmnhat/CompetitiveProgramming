#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;
int w[256], a[256];

void Init() {
    a['H'] = 1;
    a['O'] = 16;
    a['N'] = 14;
    a['C'] = 12;
}

int Weight() {
    int ans = 0, t = 1, Mol = 0;
    for (int i=0; i<s.length(); i++) {
        if ((s[i] >= 'A') && (s[i] <= 'Z')) {
            w[Mol] += a[Mol]*t;
            Mol = s[i];
            t = 1;
        }
        if ((s[i] >= '2') && (s[i] <= '9')) {
            t = (s[i] - '0');
        }
    }
    w[Mol] += a[Mol]*t;
    return w['H'] + w['O'] + w['N'] + w['C'];
}

int main()
{
    freopen("MOLECULAR.INP", "r", stdin);
    freopen("MOLECULAR.OUT", "w", stdout);
    cin >> s;
    Init();
    cout << Weight();
    return 0;
}
