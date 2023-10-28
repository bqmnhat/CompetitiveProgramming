#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m;
map <string, int> mapn, mapm;

void Solve() {
    string s;
    for (int i = 1; i <= n; i++) {
        getline(cin, s);
        mapn[s]++;
    }
    for (int i = 1; i<=m; i++) {
        getline(cin, s);
        mapm[s]++;
    }
    int MaxBallot = 0;
    string Winner;
    for (auto& i: mapm) {
        if ((mapn.find(i.first) != mapn.end()) && (i.second > MaxBallot)) {
            MaxBallot = i.second;
            Winner = i.first;
        }
    }
    cout << Winner;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cin.ignore();
    Solve();
    return 0;
}
