#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;

void Factorise(ll n) {
    ll m = sqrt(n);
    int i = 2;
    bool exist = false;
    while ((i <= m) && (n > 1)) {
        while (n%i == 0) {
            if (!exist)
                cout << i;
            else
                cout << "*" << i;
            exist = true;
            n = n/i;
        }
        i++;
    }
    if (n > 1)
        if (!exist)
            cout << n;
        else
            cout << "*" << n;
}

int main()
{
    cin >> n;
    Factorise(n);
    return 0;
}
