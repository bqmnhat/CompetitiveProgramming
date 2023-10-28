#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
ll n;

bool HHChecker(ll n) {
    ll sum = 0;
    for (ll i = 2; i <= ll(sqrt(n)); i++) {
        if (n%i == 0) {
            sum = sum + i + ll(n/i);
        }
    }
    sum = sum + 1;
    if (int(sqrt(n)) * int(sqrt(n)) == n)
        sum = sum - sqrt(n);
    if (sum == n)
        return true;
    else
        return false;
}

int main()
{
    freopen("hoanhao.inp", "r", stdin);
    freopen("hoanhao.out", "w", stdout);
    cin >> n;
    if (HHChecker(n) == true)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
