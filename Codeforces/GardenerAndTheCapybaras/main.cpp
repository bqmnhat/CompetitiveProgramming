#include <iostream>
#include <bits/stdc++.h>
#define MaxN 500
using namespace std;
int t;
string s;

void SolveTestCase() {
    string a, b, c;
    a = b = c = "";
    int n = s.length();
    for (int i=0; i<n-1; i++) {
        for (int j=i+2; j<n; j++) {
            a = s.substr(0, i+1);
            b = s.substr(i+1, j-i-1);
            c = s.substr(j, n-j);
            if (((b <= a) && (b <= c)) || ((b >= a) && (b >= c))) {
                cout << a << ' ' << b << ' ' << c << '\n';
                return;
            }
        }
    }
    cout << ":\n";
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> s;
        SolveTestCase();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
