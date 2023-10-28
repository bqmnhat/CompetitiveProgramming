#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;

void Solve() {
    if (n == 2) {
        cout << "white\n1 2";
        return;
    }
    if (n&1)
        cout << "black";
    else
        cout << "white\n1 2";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    Solve();
    return 0;
}
