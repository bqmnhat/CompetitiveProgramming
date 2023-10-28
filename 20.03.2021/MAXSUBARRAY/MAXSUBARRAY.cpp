#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a[200001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

long long Solution() {
    long long ans = -2e9, tmp = 0;
    for (int i=1; i<=n; i++) {
        tmp = tmp + a[i];
        if (tmp > ans)
            ans = tmp;
        if (tmp < 0)
            tmp = 0;
    }
    return ans;
}

int main()
{
    freopen("MAXSUBARRAY.INP", "r", stdin);
    freopen("MAXSUBARRAY.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
