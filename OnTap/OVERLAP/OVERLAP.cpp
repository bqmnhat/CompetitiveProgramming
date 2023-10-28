#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, tv[1001], dp[1001], ans[1001];
struct Seg {
    int a, b, index;
} x[1001];

bool CmpSeg(Seg x, Seg y) {
    return (x.b < y.b);
}

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> x[i].a >> x[i].b;
        x[i].index = i;
    }
}

void PrintAns(int Id) {
    int t, ka;
    t = ka = dp[Id];
    while (Id > 0) {
        ans[ka] = x[Id].index;
        ka--;
        Id = tv[Id];
    }
    cout << t << '\n';
    for (int i=1; i<=t; i++)
        cout << ans[i] << '\n';
}

void Solve() {
    sort(x+1, x+1+n, CmpSeg);
    int Max = 0, MaxID = 0;
    dp[1] = 1;
    for (int i=2; i<=n; i++) {
        int tmp = 0, id = 0;
        for (int j=1; j<i; j++) {
            if ((x[j].b == x[i].a) && (dp[j] > tmp)) {
                tmp = dp[j];
                id = j;
            }
        }
        dp[i] = tmp + 1;
        tv[i] = id;
        if (dp[i] > Max) {
            Max = dp[i];
            MaxID = i;
        }
    }
    PrintAns(MaxID);
}

int main()
{
    freopen("OVERLAP.INP", "r", stdin);
    freopen("OVERLAP.OUT", "w", stdout);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
