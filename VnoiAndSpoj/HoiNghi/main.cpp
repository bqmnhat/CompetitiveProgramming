#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, k;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    if (k == 1) {
        cout << 2;
        return 0;
    }
    if (n%2 == 1) {
        if (k >= n)
            cout << n;
        else
            cout << k + 1;
    }
    else {
        if (2*k >= n)
            cout << n/2;
        else
            cout << k+1;
    }
    return 0;
}
