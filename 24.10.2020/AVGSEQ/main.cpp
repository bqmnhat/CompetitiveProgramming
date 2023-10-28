#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int a[100];

void ReadData(int a[], int n) {
    for (int i = 1; i<=n; i++) {
        cin >> a[i];
    }
}

void Solve(int a[], int n) {
    cout << a[1] << " ";
    for (int i = 2; i<=n; i++) {
        cout << (a[i]*i) - (a[i-1]*(i-1)) << " ";
    }
}

int main()
{
    int n;
    freopen("AVGSEQ.INP", "r", stdin);
    freopen("AVGSEQ.OUT", "w", stdout);
    cin >> n;
    ReadData(a,n);
    Solve(a,n);
    return 0;
}
