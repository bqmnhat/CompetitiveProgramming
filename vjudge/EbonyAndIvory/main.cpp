#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a, b, c;

bool Solution() {
    int x = c/a;
    for (int i=0; i<=x; i++)
        if (((c - (i*a))%b) == 0)
            return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b >> c;
    if (Solution())
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
