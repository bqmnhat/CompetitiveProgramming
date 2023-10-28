#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long a,b;
int t;

int main()
{
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> a >> b;
        cout << (a^(a&b)) + (b^(a&b)) << '\n';
    }
    return 0;
}
