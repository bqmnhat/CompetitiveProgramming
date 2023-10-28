#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;

ll GiaiThua() {
    ll ans = 1;
    if (n == 0)
        return 0;
    for (int i=2; i<=n; i++)
        ans = ans*i;
    return ans;
}

int main()
{
    cin >> n;
    cout << GiaiThua();
    return 0;
}
