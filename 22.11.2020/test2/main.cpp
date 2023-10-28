#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long n;
int a[1000001];

void Make1e6() {
    int p = 2;
    for (int i=1 ;i<=1000000; i++) {
        a[i] = (p - 1)%1000000007;
        p = (p*2)%1000000007;
    }
}

void Solve() {
    if (n <= 1000000) {
        cout << a[n];
    }
    else {
        i = 1000000;
        int d;
        while (n>0) {

        }
    }
}

int main()
{
    cin >> n;
    Solve();
    return 0;
}
