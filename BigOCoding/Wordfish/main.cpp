#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;

bool CmpChar(char a, char b) {
    return (a > b);
}

void SolveTestCases() {
    int MaxMinDif = 1e9, l = s.length(), i = 0;
    string tmp = s, Ans = s;
    for (int i=1; i<l; i++)
        MaxMinDif = min(MaxMinDif, abs(int(tmp[i] - tmp[i-1])));

    while ((next_permutation(tmp.begin(), tmp.end(), CmpChar)) && (i < 10)) {
        i++;
        int MinDif = 1e9;
        for (int i=1; i<l; i++)
            MinDif = min(MinDif, abs(int(tmp[i] - tmp[i-1])));
        if (MinDif >= MaxMinDif) {
            MaxMinDif = MinDif;
            Ans = tmp;
        }
    }
    i = 0;
    tmp = s;
    while (next_permutation(tmp.begin(), tmp.end()) && (i < 10)) {
        i++;
        int MinDif = 1e9;
        for (int i=1; i<l; i++)
            MinDif = min(MinDif, abs(int(tmp[i] - tmp[i-1])));
        if (MinDif > MaxMinDif) {
            MaxMinDif = MinDif;
            Ans = tmp;
        }
    }
    cout << Ans << MaxMinDif;
}

void Solve() {
    while (cin >> s) {
        SolveTestCases();
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    //cin >> s;
    //SolveTestCases();
    return 0;
}
