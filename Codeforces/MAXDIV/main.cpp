#include <iostream>
#include <bits/stdc++.h>
#define MaxN 300000
using namespace std;
typedef long long ll;
int n;
ll k, a[MaxN+1];
vector<int> pos;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

ll Solution() {
    pos.push_back(0);
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        if (a[i] % k == 0) {
            pos.push_back(i);
            cnt++;
        }
    }
    pos.push_back(n+1);
    ll ans = 0;
    for (int i=1; i<=cnt; i++) {
        ll x = pos[i] - pos[i-1] - 1LL, y = pos[i+1] - pos[i];
        ans += x*(x+1LL)/2 + (x+1LL)*y;
    }
    ll x = pos[cnt+1] - pos[cnt] - 1LL;
    ans += x*(x+1LL)/2;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ReadData();
    cout << Solution();
    return 0;
}
