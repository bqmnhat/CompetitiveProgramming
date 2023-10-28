#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t,n;
long long a[100001], prefix[100001];
map<int, int> m;
string s;

void SplitData() {
    int l = s.length();
    for (int i=0; i<n; i++)
        a[i+1] = s[i] - '0';
}

long long Solution() {
    long long ans = 0;
    for (int i=1; i<=n; i++)
        prefix[i] = prefix[i-1] + a[i];
    for (int i=0; i<=n; i++)
        m[prefix[i] - i]++;
    for (auto i: m)
        if (i.second != 0)
            ans += ((i.second * (i.second-1LL))/2);
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> s;
        SplitData();
        m.clear();
        cout << Solution() << '\n';
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
