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
        if (a[i] > 0)
            cntPos++;
        else if (a[i] < 0)
            cntNeg++;
        else
            cntZero++;
    }
    if ((cntPos >= 3) || (cntNeg >= 3)) {
        cout << "NO\n";
        return;
    }
    vector<int> NewA;
    NewA.clear();
    NewA.push_back(0);
    for (int i=1; i<=n; i++)
        if (a[i] != 0)
            NewA.push_back(a[i]);
    if (cntZero >= 2) {
        NewA.push_back(0);
        NewA.push_back(0);
    }
    else if (cntZero == 1)
        NewA.push_back(0);
    int NewN = NewA.size()-1;
    for (int i=1; i<=NewN; i++) {
        for (int j=1; j<=NewN; j++) {
            if (j == i)
                continue;
            for (int k = 1; k<=NewN; k++) {
                if ((k == j) || (k == i))
                    continue;
                if (mark.find(NewA[i] + NewA[j] + NewA[k]) == mark.end()) {
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
        cin >> n;
        mark.clear();
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
