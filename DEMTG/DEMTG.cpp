#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long d,n;

long long Solution() {
    long long ans = (n+1)*(((d+2)*(d+1))/2);
    return ans;
}

int main()
{
    freopen("DEMTG.INP", "r", stdin);
    freopen("DEMTG.OUT", "w", stdout);
    cin >> d >> n;
    cout << Solution();
    return 0;
}
