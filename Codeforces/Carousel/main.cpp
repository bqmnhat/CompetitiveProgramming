#include <iostream>
#include <bits/stdc++.h>
#define MaxN 200000
using namespace std;
int q, n, t[MaxN+5], difVal[MaxN+5];

void ReadData() {
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        difVal[i] = difVal[i-1];
        if (t[i] != t[i-1])
            difVal[i]++;
    }
}

void SolveTestCase() {
    if (difVal[n] == 1) {
        cout << 1 << '\n';
        for (int i = 1; i <= n; i++)
            cout << 1 << ' ';
        cout << '\n';
        return;
    }
    int cntCl = 1, cl = 1;
    if ((n % 2 == 0) || (t[1] == t[n])) {
        cout << 2 << '\n';
        for (int i = 1; i <= n; i++) {
            int ans = (cl == 1)? 1 : 2;
            cout << ans << ' ';
            cl = 1 - cl;
        }
        cout << '\n';
    }
    else {
        bool foundSolutionFor2 = false;
        for (int i = 1; i < n; i++) {
            if (t[i] == t[i + 1]) {
                foundSolutionFor2 = true;
                break;
            }
        }
        int samePairs = 0;
        if (foundSolutionFor2) {
            cout << 2 << '\n' << 1 << ' ';
            for (int i = 2; i <= n; i++) {
                if ((t[i] == t[i-1]) && (samePairs < 1))
                    samePairs++;
                else
                    cl = 1 - cl;
                int ans = (cl == 1)? 1 : 2;
                cout << ans << ' ';
            }
            cout << '\n';
        } else {
            cout << 3 << '\n' << 1 << ' ';
            for (int i = 2; i < n; i++) {
                if (t[i] != t[i-1])
                    cl = 1 - cl;
                int ans = (cl == 1)? 1 : 2;
                cout << ans << ' ';
            }
            cout << 3 << '\n';
        }
    }
}

void Solve() {
    for (int i = 1; i <= q; i++) {
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
    cin >> q;
    Solve();
    return 0;
}
