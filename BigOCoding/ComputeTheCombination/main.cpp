#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> n;
        if (n == 0)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
