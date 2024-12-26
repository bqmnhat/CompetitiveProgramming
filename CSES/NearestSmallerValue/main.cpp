#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int n, pos[MaxN+5];
ll a[MaxN+5];
vector<ll> stk;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void Solve() {
    stk.push_back(n);
    for (int i=n-1; i>=1; i--) {
        while ((!stk.empty()) && (a[stk.back()] > a[i])) {
            ll tmp = stk.back();
            stk.pop_back();
            pos[tmp] = i;
        }
        stk.push_back(i);
    }
    for (int i=1; i<=n; i++)
        cout << pos[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}

