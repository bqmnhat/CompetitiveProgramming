#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[4];

ll Max3() {
    ll ans = 0;
    for (int i=1; i<=3; i++) {
        if (a[i] > ans)
            ans = a[i];
    }
    return ans;
}

int main()
{
    cin >> a[1] >> a[2] >> a[3];
    cout << Max3();
    return 0;
}
