#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

ll Sum() {
    ll ans = 0;
    for (int i=1; i<=n; i++) {
        ans += i;
    }
    return ans;
}

int main()
{
    cin >> n;
    cout << Sum();
    return 0;
}
