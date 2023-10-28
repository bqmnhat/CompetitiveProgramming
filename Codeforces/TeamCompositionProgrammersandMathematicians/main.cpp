#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, a, b;

int Groups() {
    if (a > b)
        swap(a,b);
    if (a <= ((a+b)/4))
        return a;
    else
        return ((a+b)/4);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> a >> b;
        cout << Groups() << '\n';
    }
    return 0;
}
