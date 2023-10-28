#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t;
string s;

void Solve() {
    int a,b,c;
    a = b = c = 0;
    for (int i=0; i<s.length(); i++) {
        if (s[i] == 'A')
            a++;
        else if (s[i] == 'B')
            b++;
        else
            c++;
    }
    if (b == (a+c))
        cout << "YES";
    else
        cout << "NO";
    cout << '\n';
}

int main()
{
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> s;
        Solve();
    }
    return 0;
}
