#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long a[101], dd[3];
int t, n;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        a[i] = a[i]%3;
        dd[a[i]]++;
    }
}

long long Solution() {
    long long ans = dd[0];
    if (dd[1] < dd[2]) {
        ans += dd[1];
        dd[2] = dd[2] - dd[1];
        dd[1] = 0;
    }
    else {
        ans += dd[2];
        dd[1] = dd[1] - dd[2];
        dd[2] = 0;
    }
    ans += (dd[2]/3);
    ans += (dd[1]/3);
    return ans;
}

int main()
{
    cin >> t;
    for (int i=1; i<=t; i++) {
        dd[0] = 0;
        dd[1] = 0;
        dd[2] = 0;
        cin >> n;
        ReadData();
        cout << Solution() << '\n';
    }
    return 0;
}
