#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
struct pii {
    long long t, m;
};

pii Solution(int k) {
    pii par,child;
    if (k == 1) {
        par.t = 1;
        par.m = 1;
        return par;
    }
    if (k%2 == 0) {
        par = Solution(k/2);
        child.t = par.t;
        child.m = par.t+par.m;
    }
    else {
        par = Solution((k-1)/2);
        child.t = par.t+par.m;
        child.m = par.m;
    }
    return child;
}

int main()
{
    freopen("FRACTION.INP", "r", stdin);
    freopen("FRACTION.OUT", "w", stdout);
    cin >> n;
    cout << Solution(n+1).t << " " << Solution(n+1).m;
    return 0;
}
