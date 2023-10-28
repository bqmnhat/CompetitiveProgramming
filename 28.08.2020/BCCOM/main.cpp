#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int SumOfDig(int a) {
    int ans = 0;
    while (a > 0) {
        ans = ans + a%10;
        a = a/10;
    }
    return ans;
}

int ToiGian(int n) {
    while (n > 9) {
        n = SumOfDig(n);
    }
    return n;
}

int main()
{
    int n,x;
    freopen("BCCOM.INP", "r", stdin);
    freopen("BCCOM.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i<=n; i++) {
        cin >> x;
        cout << ToiGian(x) << endl;
    }
    return 0;
}
