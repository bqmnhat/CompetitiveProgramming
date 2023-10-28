#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s, t;
int tk[257], tc;

void SolveTestCases() {
    int sl = s.length();
    for (int i=0; i<sl; i++)
        tk[s[i]]++;
    if (((tk['a'] == 0) || (tk['b'] == 0) || (tk['c'] == 0)) || (t != "abc")) {
        sort(s.begin(), s.end());
        cout << s;
    }
    else {
        for (int i=1; i<=tk['a']; i++)
            cout << 'a';
        for (int i=1; i<=tk['c']; i++)
            cout << 'c';
        for (int i=1; i<=tk['b']; i++)
            cout << 'b';
        for (int i='d'; i<='z'; i++) {
            if (tk[i] != 0)
                for (int j=1; j<=tk[i]; j++)
                    cout << char(i);
        }
    }
    for (int i='a'; i<='z'; i++)
        tk[i] = 0;
    cout << '\n';
}

void Solve() {
    for (int i=1; i<=tc; i++) {
        cin >> s >> t;
        SolveTestCases();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> tc;
    Solve();
    return 0;
}
