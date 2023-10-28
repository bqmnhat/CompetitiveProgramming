#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
#define MaxN2 100000
using namespace std;
int t, n;

bool Solution() {
    vector<int> a[n+1];
    map<int, int> CntBit;
    for (int i=1; i<=n; i++) {
        int k;
        cin >> k;
        a[i].resize(k);
        for (int j=0; j<k; j++) {
            cin >> a[i][j];
            CntBit[a[i][j]]++;
        }
    }
    bool Exist = false;
    for (int i=1; i<=n; i++) {
        bool IsGood = true;
        for (int x: a[i]) {
            if (CntBit[x] <= 1) {
                IsGood = false;
                break;
            }
        }
        if (IsGood) {
            Exist = true;
            break;
        }
    }
    return Exist;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        if (Solution())
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
