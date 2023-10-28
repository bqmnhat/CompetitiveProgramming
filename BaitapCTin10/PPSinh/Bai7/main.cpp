#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, a[201];
string Nam[101], Nu[101];

void ReadData() {
    for (int i=0; i<n; i++)
        cin >> Nam[i];
    for (int i=1; i<=n; i++)
        cin >> Nu[i];
}

void Init() {
    for (int i=1; i<=2*n; i++)
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
    int i = 2*n;
    while ((i >= 1) && (a[i] >= a[i+1]))
        i--;
    if (i < 1)
        return false;
    int j = 2*n;
    while (a[j] <= a[i])
        j--;
    swap(a[i], a[j]);
    Reverse(i+1,2*n);
    return true;
}

bool CheckMaleFemale() {
    for (int i=2; i<=2*n; i++)
        if (a[i]%2 == a[i-1]%2)
            return false;
    if (a[1]%2 == a[2*n]%2)
        return false;
    return true;
}

void PrintPermutation() {
    for (int i=1; i<=2*n; i++) {
        if (a[i]%2 == 0)
            cout << Nu[a[i]/2] << " ";
        else
            cout << Nam[a[i]/2] << " ";
    }
    cout << '\n';
}

void Solve() {
    PrintPermutation();
    while (NextPermutation()) {
        if (CheckMaleFemale())
            PrintPermutation();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai7.INP", "r", stdin);
    freopen("Bai7.OUT", "w", stdout);
    cin >> n;
    a[n+1] = -1e9;
    ReadData();
    Init();
    Solve();
    return 0;
}
