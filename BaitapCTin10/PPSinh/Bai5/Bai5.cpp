#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,k, a[101];

void Init() {
    for (int i=1; i<=k; i++)
        a[i] = i;
}

bool NextSubSet() {
    int i = k;
    while ((i >= 1) && (a[i] >= (n-k+i)))
        i--;
    if (i >= 1) {
        a[i]++;
        for (int j = i+1; j<=k; j++) {
            a[j] = a[j-1]+1;
        }
        return true;
    }
    else
        return false;
}

void PrintSubSet1() {
    for (int i=1; i<=k; i++) {
        if (a[i] != 0)
            cout << a[i];
    }
    cout << '\n';
}

void PrintSubSet2(int k) {
    int la = 0;
    while (k > 0) {
        int tmp = (k&1);
        k = (k>>1);
        la++;
        if (tmp == 1)
            cout << la;
    }
    cout << '\n';
}

void Solve() {
    int tmp = (1<<n);
    cout << "Cach1: " << '\n';
    for (int i=1; i<tmp; i++)
        PrintSubSet2(i);
    cout << '\n' << "Cach2: " << '\n';
    for (k=1; k<=n; k++) {
        Init();
        PrintSubSet1();
        while (NextSubSet())
            PrintSubSet1();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai5.INP", "r", stdin);
    freopen("Bai5.OUT", "w", stdout);
    cin >> n;
    Solve();
    return 0;
}
