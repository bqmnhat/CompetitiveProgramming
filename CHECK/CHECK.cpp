#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s[101];
int n;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> s[i];
    }
}

bool IsTrue(string a) {
    for (int i=0; i<a.length(); i++) {
        if ((a[i] - 0) % 2 != (i+1)%2) {
            return false;
        }
    }
    return true;
}

void Solve() {
    for (int i=1; i<=n; i++) {
        if (IsTrue(s[i]) == true) {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
}

int main()
{
    freopen("CHECK.INP", "r", stdin);
    freopen("CHECK.OUT", "w", stdout);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}

