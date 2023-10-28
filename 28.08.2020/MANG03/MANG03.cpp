#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int a[10000];

void ReadData(int a[], int n) {
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

bool IsPrime(int n) {
    int m = int(sqrt(n));
    if (n <= 1)
        return false;
    for (int i = 2; i<=m; i++) {
        if (n%i == 0)
            return false;
    }
    return true;
}

int PrimeIn(int a[], int n) {
    int c = 0;
    for (int i = 1; i <= n; i++) {
        if (IsPrime(a[i]))
            c = c + 1;
    }
    return c;
}

int main()
{
    int n;
    freopen("MANG03.INP", "r", stdin);
    freopen("MANG03.OUT", "w", stdout);
    cin >> n;
    ReadData(a,n);
    cout << PrimeIn(a,n);
    return 0;
}
