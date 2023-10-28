#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int a[10000];

bool IsPrime(int x) {
    int m = sqrt(x);
    if (x <= 1)
        return false;
    for (int i = 2; i<=m; i++) {
        if (x%i == 0)
            return false;
    }
    return true;
}

int PrimeIndex(int a[], int n) {
    int ans = -1, tmp = -1;
    for (int i=1; i<=n; i++) {
        if (IsPrime(a[i])) {
            if (a[i] > tmp) {
                tmp = a[i];
                ans = i;
            }
        }
    }
    return ans;
}

void ReadData(int a[], int n) {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

int main()
{
    int n;
    freopen("MANG06.INP", "r", stdin);
    freopen("MANG06.OUT", "w", stdout);
    cin >> n;
    ReadData(a,n);
    cout << PrimeIndex(a,n);
    return 0;
}
