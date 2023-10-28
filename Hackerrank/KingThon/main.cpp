#include <iostream>
#include <bits/stdc++.h>
#define MaxN 500000
using namespace std;
int n, m;
vector<int> s, t;

void ReadData() {
    for (int i=1; i<=n; i++) {
        int ai;
        cin >> ai;
        s.push_back(ai);
    }
    for (int i=1; i<=m; i++) {
        int ai;
        cin >> ai;
        t.push_back(ai);
    }
    for (int i=0; i<s.size()-1; i++)
        s[i] = s[i+1]-s[i];
    s.pop_back();
    for (int i=0; i<t.size()-1; i++)
        t[i] = t[i+1]-t[i];
    t.pop_back();
}

vector<int> MakeZFunction(vector<int> a) {
    int n = a.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i=1; i<n; i++) {
        if (i <= r)
            z[i] = min(z[i-l], r-i+1);
        while ((i + z[i] < n) && (a[z[i]] == a[z[i] + i]))
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

int Solution() {
    int tl = t.size();
    t.push_back(1e9+7);
    for (auto x: s)
        t.push_back(x);
    vector<int> z = MakeZFunction(t);
    int ans = 0;
    int zl = z.size();
    for (int i=tl; i<zl; i++)
        if (z[i] == tl)
            ans++;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    cout << Solution();
    return 0;
}
