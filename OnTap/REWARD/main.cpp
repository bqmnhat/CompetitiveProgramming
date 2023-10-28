#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
struct Work {
    int t, d;
} a[200001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i].t >> a[i].d;
    }
}

bool CmpWork(Work a, Work b) {
    if (a.t == b.t) {
        return (a.d < b.d);
    }
    return (a.t < b.t);
}

long long MaxReward() {
    long long ans = 0, t = 0;
    sort(a+1, a+1+n, CmpWork);
    for (int i=1; i<=n; i++) {
        t += a[i].t;
        ans = ans + (a[i].d - t);
    }
    return ans;
}

int main()
{
    freopen("REWARD.INP", "r", stdin);
    freopen("REWARD.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << MaxReward();
    return 0;
}
