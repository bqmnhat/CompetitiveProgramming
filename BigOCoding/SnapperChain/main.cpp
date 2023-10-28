#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long t, n, k;

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> k;
        long long Cycle = (1 << n);
        long long st = Cycle - 1;
        cout << "Case #" << i << ": ";
        if ((k >= st) && ((k - st)%Cycle == 0))
            cout << "ON";
        else
            cout << "OFF";
        cout << '\n';
    }
}

int main()
{
    cin >> t;
    Solve();
    return 0;
}
