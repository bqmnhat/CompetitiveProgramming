#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
using namespace std;
int t, n;

void SolveTestCase() {
    for (int i=1; i<=n; i++)
        cout << i << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        SolveTestCase();
    }
    return 0;
}
