#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
long long a[1000001], b[1000001];

void ReadData(long long x[]) {
    for (int i=1; i<=n; i++) {
        cin >> x[i];
    }
}

long long Solution() {
    long long ans = 0;
    sort(a+1, a+1+n);
    sort(b+1, b+1+n);
    for (int i=1; i<=n; i++) {
        ans += (a[i] * b[i]);
    }
    return ans;
}

int main()
{
    freopen("FEED.INP", "r", stdin);
    freopen("FEED.OUT", "w", stdout);
    cin >> n;
    ReadData(a);
    ReadData(b);
    cout << Solution();
    return 0;
}
