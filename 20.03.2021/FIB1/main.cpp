#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int l[46],n,k,t;

void GenL() {
    l[0] = 1;
    l[1] = 1;
    for (int i=2; i<=45; i++) {
        l[i] = l[i-2] + l[i-1];
    }
}

char KthChar(int k, int n) {
    while (n > 2) {
        if (k>l[n-2]) {
            k = k - l[n-2];
            n--;
        }
        else
            n = n - 2;
    }
    if (n == 0)
        return 'a';
    else if (n == 1)
        return 'b';
    else if (k==1)
        return 'a';
    else
        return 'b';
}

void Solve() {
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> n >> k;
        cout << KthChar(k,n) << endl;
    }
}

int main()
{
    freopen("FIB1.INP", "r", stdin);
    freopen("FIB1.OUT", "w", stdout);
    GenL();
    Solve();
    return 0;
}
