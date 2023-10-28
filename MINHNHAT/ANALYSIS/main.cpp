#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;

void Factorise(int n) {
    int m = sqrt(n), i = 2, d = 0;
    while ((i<=m) && (n>1)) {
        while (n%i == 0) {
            n = n/i;
            d = d+1;
        }
        if (d>=1) {
            if(d == 1)
                cout<<i;
            else
                cout << i << "^" << d;
            if(n > 1)
                cout << ".";
        }
        d = 0;
        i = i+1;
    }
    if (n>1)
        cout << n;
}

int main()
{
    freopen("ANALYSIS.INP", "r", stdin);
    freopen("ANALYSIS.OUT", "w", stdout);
    cin >> n;
    Factorise(n);
    return 0;
}
