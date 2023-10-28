#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int T,n, Sieve[1000001], cd[1000001], WaysToTile[41];

void FindWays() {
    for (int i=0; i<4; i++)
        WaysToTile[i] = 1;
    for (int i=4; i<=40; i++)
        WaysToTile[i] = WaysToTile[i-1] + WaysToTile[i-4];
}

void MakeSieve() {
    Sieve[0] = Sieve[1] = true;
    for (int x=2; x<=1000; x++)
        for (int y=x; x*y<=1000000; y++)
            Sieve[x*y] = true;
}

void SumUp() {
    for (int i=1; i<=1000000; i++) {
        cd[i] = cd[i-1];
        if (Sieve[i] == false)
            cd[i]++;
    }
}

void Solve() {
    for (int i=1; i<=T; i++) {
        cin >> n;
        cout << cd[WaysToTile[n]] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("YARD.INP", "r", stdin);
    freopen("YARD.OUT", "w", stdout);
    FindWays();
    MakeSieve();
    SumUp();
    cin >> T;
    Solve();
    return 0;
}
