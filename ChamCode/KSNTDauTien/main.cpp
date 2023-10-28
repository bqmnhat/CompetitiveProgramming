#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
bool Sieve[5000001];

void MakeSieve() {
    int m = sqrt(5000001);
    Sieve[1] = Sieve[0] = true;
    for (int i=2; i<=m; i++) {
        if (!Sieve[i]) {
            for (int j=i; i*j<=5000001; j++)
                Sieve[i*j] = true;
        }
    }
}

void Solve() {
    int cnt = 0, i = 0;
    bool exist = false;
    while (cnt < n) {
        i++;
        if (!Sieve[i]) {
            cnt++;
            if (!exist) {
                cout << i;
                exist = true;
            }
            else
                cout << " " << i;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    MakeSieve();
    Solve();
    return 0;
}
