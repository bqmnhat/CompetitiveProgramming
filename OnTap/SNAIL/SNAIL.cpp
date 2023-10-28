#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int v,a,b;

int Solution() {
    int ans = int((v-a-1)/(a-b)) + 2;
    return ans;
}

int main()
{
    freopen("SNAIL.INP", "r", stdin);
    freopen("SNAIL.OUT", "w", stdout);
    cin >> a >> b >> v;
    cout << Solution();
    return 0;
}
