#include <iostream>
#include <bits/stdc++.h>
#define Mod 10000
using namespace std;
int ai, n, mark[10001], CyVal[10001], lc = 0;

int Solution() {
    int i = 0;
    while (!mark[ai]) {
        i++;
        if (!mark[ai])
            mark[ai] = i;
        lc++;
        CyVal[lc] = ai;
        ai = ((ai%Mod)* (ai%Mod))%Mod;
    }
    if (n < mark[ai])
        return CyVal[n];
    n = n - mark[ai] + 1;
    if (n%(i - mark[ai] + 1) == 0)
        n = i - mark[ai] + 1 + mark[ai]-1;
    else
        n = n%(i - mark[ai] + 1) + mark[ai]-1;
    return CyVal[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SEQ.INP", "r", stdin);
    freopen("SEQ.OUT", "w", stdout);
    cin >> ai >> n;
    cout << Solution();
    return 0;
}
