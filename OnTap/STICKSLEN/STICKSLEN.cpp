#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

long long MinCost() {
    sort(a+1, a+1+n);
    long long ans = 0, tv = a[(n-1)/2 + 1];
    for (int i=1; i<=n; i++) {
        ans += abs(tv - a[i]);
    }
    return ans;
}

int main()
{
    freopen("STICKSLEN.INP", "r", stdin);
    freopen("STICKSLEN.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << MinCost();
    return 0;
}
