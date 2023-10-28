#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
unordered_map<string, int> ma;
int t, n;
string s1, s2;

void SolveTestCase() {
    ma.clear();
    reverse(s2.begin(), s2.end());
    for (int i=0; i<n; i++) {
        string tmp = "";
        if (s1[i] < s2[i]) {
            tmp.push_back(s1[i]);
            tmp.push_back(s2[i]);
        }
        else {
            tmp.push_back(s2[i]);
            tmp.push_back(s1[i]);
        }
        ma[tmp]++;
    }
    int cntodd = 0, cntoddEqualPairs = 0;
    for (auto i=ma.begin(); i!=ma.end(); i++) {
        if (((*i).second)&1) {
            cntodd++;
            if ((*i).first[0] == (*i).first[1])
                cntoddEqualPairs++;
        }
    }
    if ((n%2 == cntodd) && (cntodd == cntoddEqualPairs))
        cout << "YES\n";
    else
        cout << "NO\n";
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> s1 >> s2;
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
