#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n, a[22] = {0, 1, 2, 3, 5, 7, 11, 15, 22, 30, 42, 56, 77, 101, 135, 176, 231, 297, 385, 490, 627, 792};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> n;
        cout << a[n] << '\n';
    }
    return 0;
}
