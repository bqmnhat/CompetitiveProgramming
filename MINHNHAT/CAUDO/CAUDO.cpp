#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;

void Solve() {
    int l = 1, a[100];
    while (n>0) {
        a[l] = n%2;
        n = n/2;
        l++;
    }
    l = l - 1;
    if (l < 5) {
        for (int i=1; i<=5-l; i++)
            cout << "O" << " ";
    }
    for (int i=l; i>=1; i--)
        if (a[i] == 0)
            cout << "O" << " ";
        else
            cout << "A" << " ";
}

int main()
{
    freopen("CAUDO.INP", "r", stdin);
    freopen("CAUDO.OUT", "w", stdout);
    cin >> n;
    Solve();
    return 0;
}
