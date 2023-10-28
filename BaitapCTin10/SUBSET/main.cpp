#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int k, n, a[101];

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

void PrintSubSet() {
    for (int i=1; i<=k; i++)
        cout << a[i] << " ";
    cout << '\n';
}

void Solve() {
    PrintSubSet();
    while (NextSubSet())
        PrintSubSet();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SUBSET.INP", "r", stdin);
    freopen("SUBSET.OUT", "w", stdout);
    cin >> n >> k;
    Init();
    Solve();
    return 0;
}
