#include <iostream>
#include <bits/stdc++.h>
#define MaxN 50
using namespace std;
typedef long long ll;
int n, a[MaxN+5];
ll Primes[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

bool Check(int mask, ll& Num) {
    Num = 1;
    for (int i=0; i<15; i++)
        if (mask&(1 << i))
            Num = Num*Primes[i];
    for (int i=1; i<=n; i++)
        if ((__gcd(Num, a[i]*1LL)) == 1LL)
            return false;
    return true;
}

ll Solution() {
    ll ans = 1e18, tmp;
    for (int mask=0; mask<(1 << 15); mask++)
        if (Check(mask, tmp))
            ans = min(ans, tmp);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    cout << Solution();
    return 0;
}
