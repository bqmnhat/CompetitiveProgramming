#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
typedef long long ll;
int t, n;
ll a[MaxN+1];
map<ll, int> mark;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        mark[a[i]] = 1;
    }
}

void SolveTestCase() {
    int cntPos = 0, cntNeg = 0, cntZero = 0;
    for (int i=1; i<=n; i++) {
        if (a[i] < 0)
            cntNeg++;
        if (a[i] > 0)
            cntPos++;
        if (a[i] == 0)
            cntZero++;
    }
    if ((cntNeg >= 3) || (cntPos >= 3)) {
        cout << "NO\n";
        return;
    }
    int NewN = 0;
    for (int i=1; i<=n; i++) {
        if (a[i] != 0) {
            NewN++;
            a[NewN] = a[i];
        }
    }
    if (cntZero >= 2) {
        NewN += 2;
        a[NewN-1] = a[NewN] = 0;
    }
    else if (cntZero > 0) {
        NewN++;
        a[NewN] = 0;
    }
    for (int i=1; i<=NewN; i++) {
        for (int j=1; j<=NewN; j++) {
            if (j == i)
                continue;
            for (int k=1; k<=NewN; k++) {
                if ((k == j) || (k == i))
                    continue;
                if (mark.find(a[i] + a[j] + a[k]) == mark.end()) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
}

void Solve() {
    for (int i=1; i<=t; i++) {
        mark.clear();
        cin >> n;
        ReadData();
        SolveTestCase();
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
