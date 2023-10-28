#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
map<int, int> m;

void ReadData() {
    int a, b;
    for (int i=1; i<=n; i++) {
        cin >> a >> b;
        m[a+b]++;
    }
}

int Solution() {
    int ans = 0;
    for (auto i: m)
        ans++;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("POINTSET.INP", "r", stdin);
    freopen("POINTSET.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
