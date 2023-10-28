#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[5];

ll Max4() {
    ll ans = 0;
    for (int i=1; i<=4; i++) {
        if (a[i] > ans)
            ans = a[i];
    }
    return ans;
}

int main()
{
    cin >> a[1] >> a[2] >> a[3] >> a[4];
    cout << Max4();
    return 0;
}
