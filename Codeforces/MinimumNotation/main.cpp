#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef pair<int, int> pii;
int t, n;
string s;

void SolveTestCase() {
    n = s.length();
    vector<pii> num;
    num.clear();
    for (int i=0; i<n; i++)
        num.push_back(pii(s[i] - '0', i));
    sort(num.begin(), num.end());
    vector<int> ans;
    ans.clear();
    int MaxId = 0;
    for (int i=0; i<n; i++) {
        pii tmp = num[i];
        int d = tmp.first, id = tmp.second;
        if (MaxId > id)
            ans.push_back(min(d+1, 9));
        else
            ans.push_back(d);
        MaxId = max(MaxId, id);
    }
    sort(ans.begin(), ans.end());
    for (int x: ans)
        cout << x;
    cout << '\n';
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
