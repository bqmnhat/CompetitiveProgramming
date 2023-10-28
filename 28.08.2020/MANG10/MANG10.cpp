#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int a[1000000];

void ReadData(int a[], int n) {
    for (int i = 1; i<=n; i++) {
        cin >> a[i];
    }
}

void MShift(int a[], int n, int m) {
    int NOfShift = m%n;
    for (int i = NOfShift+1; i<=n; i++) {
        cout << a[i] << " ";
    }
    for (int i = 1; i<=NOfShift; i++) {
        cout << a[i] << " ";
    }
}

int main()
{
    int n,m;
    freopen("MANG10.INP", "r", stdin);
    freopen("MANG10.OUT", "w", stdout);
    cin >> n >> m;
    ReadData(a,n);
    MShift(a,n,m);
    return 0;
}
