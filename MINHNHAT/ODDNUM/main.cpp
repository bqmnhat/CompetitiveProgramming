#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int m,n;

void Solve(int m,int n) {
    if (m%2 == 0)
        m = m + 1;
    int k = 0;
    while (m <= n) {
        cout << m << " ";
        k = k + 1;
        m = m + 2;
        if (k == 15) {
            cout << endl;
            k = 0;
        }
    }
}

int main()
{
    freopen("ODDNUM.INP", "r", stdin);
    freopen("ODDNUM.OUT", "w", stdout);
    cin >> m >> n;
    Solve(m,n);
    return 0;
}
