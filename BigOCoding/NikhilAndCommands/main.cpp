#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t,n,ld = 0;
string Dir[1000001];

void StoreDir(string s) {
    string tmp = "";
    int i = 0;
    if (s[0] == '/')
        i = 1;
    for (; i<=s.length(); i++) {
        if ((i < s.length()) && (s[i] != '/'))
            tmp = tmp + s[i];
        else {
            if (tmp == "..") {
                if (ld > 0)
                    ld--;
            }
            else {
                ld++;
                Dir[ld] = tmp;
            }
            tmp = "";
        }
    }
}

void PrintDir() {
    cout << '/';
    for (int i=1; i<=ld; i++)
        cout << Dir[i] << '/';
    cout << '\n';
}

void SolveTestCase() {
    string cmd, s;
    for (int i=1; i<=n; i++) {
        cin >> cmd;
        if (cmd == "cd") {
            cin >> s;
            if (s[0] == '/')
                ld = 0;
            StoreDir(s);
        }
        else
            PrintDir();
    }
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ld = 0;
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
