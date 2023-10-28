#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int t, n;
string s[MaxN+1];
map<string, int> ma;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> s[i];
        ma[s[i]]++;
    }
}

void SolveTestCase() {
    ma.clear();
    ReadData();
    for (int i=1; i<=n; i++) {
        int l = s[i].length();
        bool Exist = false;
        string tmp2 = "", tmp1 = s[i];
        if ((ma.find(tmp1) != ma.end()) && (ma.find(tmp2) != ma.end())) {
            cout << 1;
            Exist = true;
            continue;
        }
        for (int j=l-1; j>=0; j--) {
            tmp1.pop_back();
            tmp2 = s[i][j] + tmp2;
            if ((ma.find(tmp1) != ma.end()) && (ma.find(tmp2) != ma.end())) {
                cout << 1;
                Exist = true;
                break;
            }
        }
        if (!Exist)
            cout << 0;
    }
    cout << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
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
