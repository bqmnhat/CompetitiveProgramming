#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;

bool IsPrime() {
    ll m = sqrt(n);
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    for (int i=2; i<=m; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    cin >> n;
    if (IsPrime())
        cout << "TRUE";
    else
        cout << "FALSE";
    return 0;
}
