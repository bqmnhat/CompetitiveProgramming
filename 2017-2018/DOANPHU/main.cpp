#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[1001], n;

int Solution() {
    int MaxD = 0, aa, bb, tmp1, tmp2, ans = 0;
    for (int i = 1; i<=n; i++) {
        cin >> aa >> bb;
        tmp1 = min(aa,bb);
        tmp2 = max(aa,bb);
        for (int i=tmp1; i<=tmp2-1; i++) {
            a[i]++;
            if (a[i] > MaxD) {
                MaxD = a[i];
            }
        }
    }
    for (int i=0; i<=1000; i++) {
        if (a[i] == MaxD) {
            ans++;
        }
    }
    return ans;
}

int main()
{
    freopen("DOANPHU.INP", "r", stdin);
    freopen("DOANPHU.OUT", "w", stdout);
    cin >> n;
    cout << Solution();
    return 0;
}
