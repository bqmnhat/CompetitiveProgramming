#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, f1, f2;

int Solution() {
    f1 = f2 = 1;
    for (int i=2; i<=n; i++) {
        int tmp = (f1%10 + f2%10)%10;
        f1 = f2;
        f2 = tmp;
    }
    return f2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cout << Solution();
    return 0;
}
