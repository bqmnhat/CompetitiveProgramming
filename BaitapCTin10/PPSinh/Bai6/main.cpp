#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a[102];
string s[101];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> s[i];
}

void Init() {
    for (int i=1; i<=n; i++)
        a[i] = i;
}

void Reverse(int x, int y) {
    int i = x, j = y;
    while (i <= j) {
        swap(a[i], a[j]);
        i++;
        j--;
    }
}

bool NextPermutation() {
    int i = n;
    while ((i >= 1) && (a[i] >= a[i+1]))
        i--;
    if (i < 1)
        return false;
    int j = n;
    while (a[j] <= a[i])
        j--;
    swap(a[i], a[j]);
    Reverse(i+1,n);
    return true;
}

void PrintPermutation() {
    for (int i=1; i<=n; i++)
        cout << s[a[i]] << " ";
    cout << '\n';
}

void Solve() {
    PrintPermutation();
    while (NextPermutation())
        PrintPermutation();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai6.INP", "r", stdin);
    freopen("Bai6.OUT", "w", stdout);
    cin >> n;
    a[n+1] = -1e9;
    ReadData();
    Init();
    Solve();
    return 0;
}
