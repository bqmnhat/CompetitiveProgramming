#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool a[1000000];

void Sieve(int n, bool a[]) {
    a[1] = true;
    for (int i = 2; i<=sqrt(n); i++) {
        if (a[i] == false) {
            int j = i*i;
            while (j <= n) {
                a[j] = true;
                j = j + i;
            }
        }
    }
}

void FindHappy(int n, bool a[]) {
    for (int i = n; i>=1; --i) {
        if ((a[i] == false) or (n%i == 0))
            cout << i << " ";
    }
}

int main()
{
    int n;
    freopen("HAPPYNUM.INP", "r", stdin);
    freopen("HAPPYNUM.OUT", "w", stdout);
    cin >> n;
    if (n == 0) {
        cout << "0";
        return 0;
    }
    Sieve(n,a);
    FindHappy(n,a);
    return 0;
}
