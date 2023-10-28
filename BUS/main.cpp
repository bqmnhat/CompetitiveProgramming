#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, TotalStaff = 0;
ll TotalDelay = 0, delayTime[200009], k;
vector<ll> staff[200009];

void ReadData() {
    for (int i=0; i<n; i++) {
        cin >> delayTime[i] >> k;
        for (int j=0; j<k; j++) {
            int x;
            cin >> x;
            staff[i].push_back(x);
        }
        TotalStaff += k;
        TotalDelay += delayTime[i];
    }
    m = min(TotalStaff, m);
}

bool MaxStaff(ll delay) {
    ll cnt = 0, now = delay;
    for (int i=0; i<n; i++) {
        for (auto it: staff[i])
            if (it <= now)
                cnt++;
        now += delayTime[i];
    }
    if (cnt >= m)
        return true;
    else
        return false;
}

ll Solution() {
    ll lo = 0, hi = 1e18, ans = 0;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if(MaxStaff(mid)) {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    return (ans + TotalDelay);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BUS.INP", "r", stdin);
    freopen("BUS.OUT", "w", stdout);
    cin >> n >> m;
    ReadData();
    cout << Solution();
    return 0;
}
