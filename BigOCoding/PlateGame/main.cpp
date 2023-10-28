#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100
using namespace std;
int a, b, r;

void Solve() {
    if (2*r > min(a, b))
        cout << "Second";
    else
        cout << "First";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b >> r;
    Solve();
    return 0;
}
