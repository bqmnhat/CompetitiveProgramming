#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int n, cnt[MaxN+1];

void ReadData() {
    int ai;
    for (int i=1; i<=n; i++) {
        cin >> ai;
        cnt[ai]++;
    }
}

void Solve() {
    for (int i=1; i<=MaxN; i++) {
        if (cnt[i]&1) {
            cout << "Conan";
            return;
        }
    }
    cout << "Agasa";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
