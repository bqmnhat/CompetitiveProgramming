#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;

void Solve() {
    int x,y;
    long long MaxSum = -2e9, MinSum = 2e9, MaxSub = -2e9,MinSub = 2e9;
    for (int i = 1; i<=n; i++) {
        cin >> x >> y;
        if ((x+y)>MaxSum)
            MaxSum = x+y;
        if ((x+y)<MinSum)
            MinSum = x+y;
        if ((x-y)>MaxSub)
            MaxSub = x-y;
        if ((x-y)<MinSub)
            MinSub = x-y;
    }
    cout << max((MaxSum - MinSum),(MaxSub - MinSub));
}

int main()
{
    freopen("MAHDIST.INP", "r", stdin);
    freopen("MAHDIST.OUT", "w", stdout);
    cin >> n;
    Solve();
    return 0;
}
