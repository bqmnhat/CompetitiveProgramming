#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
long long a[301], b[301];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int i=1; i<=n; i++)
        cin >> b[i];
}

double Solution() {
    double ans = 0;
    sort(a+1, a+1+n);
    sort(b+1, b+1+n);
    for (int i=1; i<=n; i++)
        ans += abs(a[i] - b[i]);
    ans = (ans/double(n));
    return ans;
}

int main()
{
    cin >> n;
    ReadData();
    cout << fixed << setprecision(9) << Solution();
    return 0;
}
