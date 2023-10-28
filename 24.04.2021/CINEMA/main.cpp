#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[100001], b[100001], c[100001], x[100001], y[100001], n;
long long sum = 0;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        sum = sum + a[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> b[i];
        x[i] = b[i] - a[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> c[i];
        y[i] = c[i] - a[i];
    }
}

int maxpos(int a[], int id) {
    int pos = 1;
    if (pos == id)
        pos++;
    for (int i = 1; i<=n; i++) {
        if ((a[i] > a[pos]) && (i != id))
            pos = i;
    }
    return pos;
}

void Solve() {
    int i1,j1,i2,j2;
    i1 = maxpos(x,0);
    j1 = maxpos(y, i1);
    j2 = maxpos(y, 0);
    i2 = maxpos(x, j2);
    long long sum1,sum2;
    sum1 = sum + x[i1] + y[j1];
    sum2 = sum + x[i2] + y[j2];
    if (sum1 > sum2) {
        cout << sum1 << endl;
        cout << i1 << " " << j1;
    }
    else {
        cout << sum2 << endl;
        cout << i2 << " " << j2;
    }
}

int main()
{
    freopen("CINEMA.INP", "r", stdin);
    freopen("CINEMA.OUT", "w", stdout);
    cin >> n;
    ReadData();
    Solve();
    return 0;
}
