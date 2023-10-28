#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, dp[1001], tb[1001];
struct Dino {
    int w,s,id;
}a[1001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i].w >> a[i].s;
        a[i].id = i;
    }
}

bool CmpDino(Dino a, Dino b) {
    return (a.w < b.w);
}

void PrintAns(int Max, int x) {
    cout << Max << '\n';
    int tmp[1001], top = 0;
    while (x > 0) {
        top++;
        tmp[top] = a[x].id;
        x = tb[x];
    }
    while (top > 0) {
        cout << tmp[top] << " ";
        top--;
    }
}

void Solve() {
    int MaxDino = 1, MaxLastId = 1;
    sort(a+1, a+1+n, CmpDino);
    dp[1] = 1;
    for (int i=2; i<=n; i++) {
        int tmp = 0, idx = 0;
        for (int j=1; j<i; j++) {
            if ((a[j].s > a[i].s) && (dp[j] > tmp) && (a[j].w < a[i].w)) {
                tmp = dp[j];
                idx = j;
            }
        }
        dp[i] = tmp + 1;
        if (dp[i] > MaxDino) {
            MaxDino = dp[i];
            MaxLastId = i;
        }
        tb[i] = idx;
    }
    PrintAns(MaxDino, MaxLastId);
}

int main()
{
    freopen("DINOSAUR.INP", "r", stdin);
    freopen("DINOSAUR.OUT", "w", stdout);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
