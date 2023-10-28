#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
int t, n, b[MaxN+5], a[MaxN+5];
bool mark[MaxN+5], Illegal;
set<int> rNums; // Nums that are not in b[]

void ReadData() {
    Illegal = false;
    memset(mark, false, sizeof(mark));
    memset(a, 0, sizeof(a));
    rNums.clear();
    for (int i=1; 2*i<=n; i++) {
        cin >> b[i];
        if (mark[b[i]])
            Illegal = true;
        else {
            mark[b[i]] = true;
            a[2*i] = b[i];
        }
    }
    for (int i=1; i<=n; i++)
        if (!mark[i])
            rNums.insert(i);
}

void SolveTestCase() {
    if ((Illegal) || (mark[1]) || (!mark[n])) {
        cout << "-1\n";
        return;
    }
    for (int i=n/2; i>=1; i--) {
        auto it = rNums.upper_bound(a[2*i]);
        if (it == rNums.begin()) {
            cout << "-1\n";
            return;
        }
        it--;
        x:;
        a[2*i-1] = (*it);
        if (a[2*i-1] > a[2*i]) {
            cout << "-1\n";
            return;
        }
        rNums.erase(it);
    }
    for (int i=1; i<=n; i++)
        cout << a[i] << ' ';
    cout << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
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
