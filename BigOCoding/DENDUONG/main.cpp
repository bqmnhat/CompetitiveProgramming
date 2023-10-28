#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, l, a[100001];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

double MinDist() {
    sort(a+1, a+1+n);
    double ans = a[1];
    for (int i=2; i<=n; i++) {
        double tmp = double(double(a[i] - a[i-1])/(2.0));
        if (tmp > ans)
            ans = tmp;
    }
    if (l - a[n] > ans)
        ans = a[n];
    return ans;
}

int main()
{
    cin >> n >> l;
    ReadData();
    cout << fixed << setprecision(2) << MinDist();
    return 0;
}
