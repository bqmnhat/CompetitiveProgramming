#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
int n, t;
ll SumX, XorX;

void ReadData() {
    ll ai;
    SumX = XorX = 0;
    for (int i=1; i<=n; i++) {
        cin >> ai;
        SumX += ai;
        XorX ^= ai;
    }
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        vector<ll> ans;
        ans.clear();
        ll tmp = (1LL << 50) + (SumX&1);
        SumX += tmp;
        XorX ^= tmp;
        ans.push_back(tmp);
        ll Num = XorX - (SumX>>1LL);
        ans.push_back(Num);
        ans.push_back(Num);
        cout << 3 << '\n';
        for (int i = 0; i<3; i++)
            cout << ans[i] << ' ';
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
