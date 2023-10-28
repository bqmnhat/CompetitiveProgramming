#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
bool a[1000001];

void Prime() {
    int m = sqrt(n);
    a[0] = false;
    a[1] = false;
    for (int i=2; i<=m; i++) {
        if (a[i] == true) {
            int j=i*i;
            while (j<=n) {
                a[j] = false;
                j = j+i;
            }
        }
    }
}

void Factors() {
    int m = sqrt(n);
    for (int i=1; i<=m; i++) {
        if (n%i == 0) {
            a[i] = true;
            a[n/i] = true;
        }
    }
}

void Print() {
    for (int i=n; i>=1; --i) {
        if (a[i] == true)
            cout << i << " ";
    }
}

int main()
{
    freopen("HAPPYNUM.INP", "r", stdin);
    freopen("HAPPYNUM.OUT", "w", stdout);
    cin >> n;
    fill(a+1,a+1+n,true);
    Prime();
    Factors();
    Print();
    return 0;
}
