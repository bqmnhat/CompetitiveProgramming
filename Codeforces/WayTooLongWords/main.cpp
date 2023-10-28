#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
string s;

void Solve() {
    for (int i=1; i<=n; i++) {
        cin >> s;
        if (s.length() > 10)
            cout << s[0] << s.length()-2 << s[s.length()-1] << '\n';
        else
            cout << s << '\n';
    }
}

int main()
{
    cin >> n;
    Solve();
    return 0;
}
