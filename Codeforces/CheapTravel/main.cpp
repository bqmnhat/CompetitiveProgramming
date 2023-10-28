#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m,a,b;

int Solution() {
    int gr = n/m, left = n%m;
    int ans = min(gr*b, gr*m*a) + min(b, left*a);
    return ans;
}

int main()
{
    cin >> n >> m >> a >> b;
    cout << Solution();
    return 0;
}
