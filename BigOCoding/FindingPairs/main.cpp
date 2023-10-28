#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n;
long long tk[2000002];

void InitTK() {
    for (int i=0; i<=2000001; i++)
        tk[i] = 0;
}

void ReadData() {
    int ai;
    for (int i=1; i<=n; i++) {
        cin >> ai;
        tk[ai+1000000]++;
    }
}

long long Solution() {
    long long ans = 0;
    for (int i=0; i<=2000001; i++) {
        ans = ans + ((tk[i] * (tk[i]+1LL))/2);
    }
    return ans;
}

void Solve() {
    for (int i = 1; i<= t; i++) {
        cin >> n;
        InitTK();
        ReadData();
        cout << Solution() << '\n';
    }
}

int main()
{
    cin >> t;
    Solve();
    return 0;
}
