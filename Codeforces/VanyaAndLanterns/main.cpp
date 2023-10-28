#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,l, a[1001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

double Solution() {
    sort(a+1, a+1+n);
    double ans = a[1];
    for (int i=2; i<=n; i++)
        ans = max(ans, ((double)(a[i] - a[i-1])/2.00));
    ans = max(ans, (double)(l - a[n]));
    return ans;
}

int main()
{
    cin >> n >> l;
    ReadData();
    cout << fixed << setprecision(10) << Solution();
    return 0;
}
