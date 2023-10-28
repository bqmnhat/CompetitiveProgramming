#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a[1001], q, id[1001];
bool dd[1001];

void ReadData() {
    for (int i=2; i<=n; i++)
        cin >> a[i];
}

int NearestBlank(int x) {
    int cnt = 0;
    for (int i=1; i<=n; i++) {
        if (!dd[i])
            cnt++;
        if (cnt > x)
            return i;
    }
}

void MakeID() {
    for (int i=n; i>=1; i--) {
        int tmp = NearestBlank(a[i]);
        id[i] = tmp;
        dd[tmp] = true;
    }
}

void Solve() {
    int NumToFind;
    for (int i=1; i<=q; i++) {
        cin >> NumToFind;
        cout << id[NumToFind] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("HRANK.INP", "r", stdin);
    freopen("HRANK.OUT", "w", stdout);
    cin >> n >> q;
    ReadData();
    MakeID();
    Solve();
    return 0;
}
