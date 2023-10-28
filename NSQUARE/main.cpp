#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;

int Solution() {
    int m = sqrt(n);
    if (m*m == n)
        return 1;
    for (int i=m; i>=2; i--) {
        if ((n%i==0) and ((n/i)%i == 0))
            return n/(i*i);
    }
    return n;
}

int main()
{
    freopen("NSQUARE.INP", "r", stdin);
    freopen("NSQUARE.OUT", "w", stdout);
    cin >> n;
    cout << Solution();
    return 0;
}
