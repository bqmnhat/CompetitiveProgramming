#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t,a[4],d;

void Solve() {
    for (int i=1; i<=t; i++) {
        for (int j=1; j<=3; j++)
            cin >> a[j];
        cin >> d;
        sort(a+1, a+1+3);
        int ans = 1, sum = d;
        for (int j=1; j<=3; j++) {
            if (a[j] > sum) {
                ans++;
                sum = d;
            }
            sum = sum - a[j];
        }
        cout << ans << '\n';
    }
}

int main()
{
    cin >> t;
    Solve();
    return 0;
}
