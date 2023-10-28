#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;

long long DoubFact(int n) {
    int k;
    long long ans = 1;
    if (n == 0) {
        return 1;
    }
    if (n%2 == 0) {
        k = 2;
    }
    else {
        k = 3;
    }
    for (int i = 1; i<=(n/2); i++) {
            ans = ans * k;
            k = k + 2;
    }
    return ans;
}

int main()
{
    freopen("FACTO.INP", "r", stdin);
    freopen("FACTO.OUT", "w", stdout);
    cin >> n;
    cout << DoubFact(n);
    return 0;
}
