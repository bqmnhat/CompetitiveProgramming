#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, start[200001], fin[200001], f[400001], t[400001], nt = 0;
bool mark[400001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> start[i] >> fin[i];
        nt++;
        t[nt] = start[i];
        nt++;
        t[nt] = fin[i];
    }
}

int BinSearch(int val) {
    int lo = 1, hi = nt;
    while (lo <= hi) {
        int m = (lo+hi)/2;
        if (t[m] == val)
            return m;
        else if (t[m] < val)
            lo = m + 1;
        else
            hi = m - 1;
    }
    return -1;
}

void FilterFilms() {
    sort(t+1, t+1+nt);
    for (int i=1; i<=nt; i++) {
        if (t[i] == t[i-1])
            t[i] = 1e9+1;
    }
    sort(t+1, t+1+nt);
    for (int i=1; i<=n; i++) {
        int x = BinSearch(start[i]), y = BinSearch(fin[i]);
        if (x > f[y]) {
            f[y] = x;
            mark[y] = true;
        }
    }
}

int MaxFilms() {
    int t = 0, ans = 0;
    for (int i=1; i<=400000; i++) {
        if ((mark[i] == true) && (f[i] >= t)) {
            ans++;
            t = i;
        }
    }
    return ans;
}

int main()
{
    freopen("FILMS.INP", "r", stdin);
    freopen("FILMS.OUT", "w", stdout);
    cin >> n;
    ReadData();
    FilterFilms();
    cout << MaxFilms();
    return 0;
}
