#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[100000],n,m;

void Init() {
    for (int i=1; i<= n; i++) {
        a[i] = i;
    }
}

int Find(int x) {
    while (x != a[x])
        x = a[x];
    return x;
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    a[max(x,y)] = min(x,y);
}

int Dem() {
    int ans = 0;
    for (int i=1; i<=n; i++) {
        if (a[i] == i) {
            ans +=1;
        }
    }
    return ans;
}

void Solve() {
    int x,y;
    Init();
    for (int i = 1; i<=m; i++) {
        cin >> x >> y;
        Union(x,y);
    }
    cout << Dem();
}

int main()
{
    freopen("BAIGOP.INP", "r", stdin);
    freopen("BAIGOP.OUT", "w", stdout);
    cin >> n >> m;
    Solve();
    return 0;
}
