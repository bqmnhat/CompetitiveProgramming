#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
long long a[21], sum = 0;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        sum += a[i];
    }
}

long long NextSum(int x, long long preans) {
    long long tmp = 0, ans = a[x];
    preans = preans + a[x];
    for (int i=x+1; i<=n; i++) {
        if (a[i]+preans<=(sum/2)) {
            tmp = max(tmp, NextSum(i,preans));
        }
    }
    return (ans + tmp);
}

long long MinDiff() {
    long long ans = 0;
    for (int i=1; i<=n; i++) {
        long long m = 0, tmp;
        tmp = NextSum(i, m);
        if (tmp > ans)
            ans = tmp;
    }
    return abs(sum - 2*ans);
}

int main()
{
    freopen("APPDIV.INP", "r", stdin);
    freopen("APPDIV.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << MinDiff();
    return 0;
}
