#include <iostream>
#include <bits/stdc++.h>
#define MaxN 300000
using namespace std;
vector<int> f, g;
int t, n, k;

void InitData() {
    f.clear();
    g.clear();
    for (int i=0; i<n; i++)
        f.push_back(i);
    for (int i=0; i<n; i+=2)
        g.push_back(i);
    for (int i=1; i<n; i+=2)
        g.push_back(i);
}

vector<int> Permute(const vector<int>& a, const vector<int>& b) {
    vector<int> ans;
    for (int i=0; i<n; i++)
        ans.push_back(a[b[i]]);
    return ans;
}

vector<int> Exponentation(const vector<int>& origin,vector<int>& base, int e) {
    vector<int> ans = origin;
    while (e > 0) {
        if (e&1)
            ans = Permute(ans, base);
        base = Permute(base, base);
        e >>= 1;
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> k;
        InitData();
        vector<int> ans = Exponentation(f, g, k);
        for (auto x: ans)
            cout << (x+1) << ' ';
        cout << '\n';
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
