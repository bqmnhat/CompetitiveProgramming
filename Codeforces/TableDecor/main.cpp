#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long a[4];

int main()
{
    cin >> a[1] >> a[2] >> a[3];
    long long ans = (a[1] + a[2] + a[3])/3;
    sort(a+1, a+1+3);
    if (a[1] + a[2] < ans)
        ans = a[1] + a[2];
    cout << ans;
    return 0;
}
