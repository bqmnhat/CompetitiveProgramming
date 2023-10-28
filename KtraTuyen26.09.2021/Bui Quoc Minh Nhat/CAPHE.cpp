#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, m;
int t1,t2,t = 0, now = 1;

double Solution() {
    int td, tab;
    long long sum = 0;
    double ans = 0;
    for (int i=1; i<=m; i++) {
        cin >> td >> tab;
        if (t < td)
            t = td;
        int tmp = 0;
        if (now <= tab)
            tmp = min(tab - now, now+n - tab);
        else
            tmp = min(now - tab, tab+n - now);
        t = t + tmp*t1 + t2;
        sum = sum + (t - td);
        now = tab;
    }
    ans = double(double(sum)/double(m));
    return ans;
}

int main()
{
    freopen("CAPHE.INP", "r", stdin);
    freopen("CAPHE.OUT", "w", stdout);
    cin >> n >> t1 >> t2 >> m;
    cout << fixed << setprecision(3) << Solution();
    return 0;
}
