#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,c,k,t[1000002];

void ReadData() {
    int a,b;
    for (int i=1; i<=n; i++) {
        cin >> a >> b;
        if (a>=k)
            t[i] = 0;
        else if (b == 0)
            t[i] = 2e9;
        else
            t[i] = (k-a-1)/b + 1;
    }
}

int MaxAward() {
    int ans = 0, i = 1;
    sort(t+1,t+1+n);
    while ((i <= n) && (c - t[i] >= 0)) {
        c = c - t[i];
        ans++;
        i++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("OLYMP.INP", "r", stdin);
    freopen("OLYMP.OUT", "w", stdout);
    cin >> n >> c >> k;
    ReadData();
    cout << MaxAward();
    return 0;
}
