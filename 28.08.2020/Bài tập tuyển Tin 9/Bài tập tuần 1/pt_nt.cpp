#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

void Factorise(int n) {
    int m = int(sqrt(n));
    int i = 2;
    while ((n>1) && (i<=m)) {
        while (n%i == 0) {
            cout << i << " ";
            n = n/i;
        }
        i++;
    }
    if (n>1)
        cout << n;
}

int main()
{
    int n;
    freopen("pt_nt.inp", "r", stdin);
    freopen("pt_nt.out", "w", stdout);
    cin >> n;
    Factorise(n);
    return 0;
}
