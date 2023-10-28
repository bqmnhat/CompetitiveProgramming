#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int p[200001], n, q, MaxNum = 0, ka = 0, kb = 0;
struct Ans {
    int first, second;
}a[100001], b[1000001];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> p[i];
        if (p[i] > MaxNum)
            MaxNum = p[i];
    }
}

void MakeAns() {
    int i=1, j=2;
    while (p[i] != MaxNum) {
        while (p[i] > p[j]) {
            n++;
            p[n] = p[j];
            ka++;
            a[ka].first = p[i];
            a[ka].second = p[j];
            j++;
        }
        ka++;
        a[ka].first = p[i];
        a[ka].second = p[j];
        n++;
        p[n] = p[i];
        i = j;
        j++;
    }
    while (j <= n) {
        kb++;
        b[kb].first = p[i];
        b[kb].second = p[j];
        j++;
    }
}

void Solve() {
    long long x;
    for (int i=1; i<=q; i++) {
        cin >> x;
        if (x <= ka)
            cout << a[x].first << " " << a[x].second << endl;
        else {
            x = x - ka;
            long long y = (x-1)%kb + 1;
            cout << b[y].first << " " << b[y].second << endl;
        }
    }
}

int main()
{
    freopen("CODERS.INP", "r", stdin);
    freopen("CODERS.OUT", "w", stdout);
    cin >> n;
    ReadData();
    MakeAns();
    cin >> q;
    Solve();
    return 0;
}
