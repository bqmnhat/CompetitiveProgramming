#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long m,n,k;

long long Solution() {
    long long HorCut1 = min(k/2, m-1), VerCut2 = min(k/2, n - 1);
    long long VerCut1 = min(k - HorCut1, n - 1), HorCut2 = min(k - VerCut2, m - 1);
    long long ans = max((HorCut1 + 1LL) * (VerCut1 + 1LL), (HorCut2+1LL) * (VerCut2+1LL));
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CUT.INP", "r", stdin);
    freopen("CUT.OUT", "w", stdout);
    cin >> m >> n >> k;
    cout << Solution();
    return 0;
}
