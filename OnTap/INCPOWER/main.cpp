#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int P,n,d, a[1000001];
double ans;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

double Solution() {
    double ans = P;
    sort(a+1, a+1+n);
    for (int i=1; i<=n; i++) {
        ans = max(double((ans*(100+a[i]))/100), ans+d);
    }
    return ans;
}

int main()
{
    freopen("INCPOWER.INP", "r", stdin);
    freopen("INCPOWER.OUT", "w", stdout);
    cin >> P >> n >> d;
    ReadData();
    ans = Solution();
    cout << fixed << setprecision(6) << ans;
    return 0;
}
