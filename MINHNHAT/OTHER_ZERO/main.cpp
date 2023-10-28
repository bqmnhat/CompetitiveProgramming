#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;

int NonZero() {
    int tmp = 1;
    for (int i=2; i<=n; i++) {
        int j = i;
        tmp = tmp * i;
        while (j%5 == 0) {
            j = j/5;
            tmp = tmp/10;
        }
        tmp = tmp % 10;
    }
    return tmp;
}

int main()
{
    freopen("OTHER_ZERO.INP", "r", stdin);
    freopen("OTHER_ZERO.OUT", "w", stdout);
    cin >> n;
    cout << NonZero();
    return 0;
}
