#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long n,m,a;

long long Solution() {
    long long ans = (((n-1LL)/a)+1LL)*(((m-1LL)/a)+1LL);
    return ans;
}

int main()
{
    cin >> n >> m >> a;
    cout << Solution();
    return 0;
}
