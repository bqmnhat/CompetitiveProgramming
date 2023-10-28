#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;

bool IsSquare(ll n) {
    return ((sqrt(n) * sqrt(n)) == n);
}

bool IsPerfect(ll n)  {
    if (n < 0)
        return false;
    if (n == 0)
        return true;
    ll sumdiv = 1, m = sqrt(n);
    for (int i=2; i<=m; i++) {
        if (n%i == 0) {
            sumdiv = sumdiv + i + (n/i);
        }
        if (sumdiv > n)
            return false;
    }
    if (IsSquare(n))
        sumdiv = sumdiv - sqrt(n);
    if (sumdiv == n)
        return true;
    else
        return false;
}

int main()
{
    cin >> n;
    if (IsPerfect(n))
        cout << "TRUE";
    else
        cout << "FALSE";
    return 0;
}
