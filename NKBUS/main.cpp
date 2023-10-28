#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int sum = 0, a[200001], n, m, l = 0;

int Solution() {
    int k,t;
    for (int i=1; i<=n; i++) {
        cin >> t;
        cin >> k;
        while (k>0) {
            l++;
            cin >> a[l];
            a[l] = a[l] - sum;
            k--;
        }
        sum += t;
    }
    sort(a+1, a+1+l);
    if (l<=m) {
        for (int i=1; i<=l; i++) {
            if (a[i] >= 0)
                sum += a[i];
        }
    }
    else {
        for (int i=1; i<=m; i++) {
            if (a[i] >= 0)
                sum += a[i];
        }
    }
    return sum;
}

int main()
{
    freopen("NKBUS.INP", "r", stdin);
    freopen("NKBUS.OUT", "w", stdout);
    cin >> n >> m;
    cout << Solution();
    return 0;
}
