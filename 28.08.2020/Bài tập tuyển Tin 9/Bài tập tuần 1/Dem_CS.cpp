#include <iostream>
#include <cstdio>
using namespace std;

int CountDig(int n, int &d) {
    d = 0;
    int sum = 0;
    while (n > 0) {
        sum = sum + n % 10;
        n = n / 10;
        d = d + 1;
    }
    return sum;
}

int main()
{
    int n,d,sumdig;
    freopen("Dem_CS.inp", "r", stdin);
    freopen("Dem_CS.out", "w", stdout);
    cin >> n;
    sumdig = CountDig(n, d);
    cout << d << endl;
    cout << sumdig;
    return 0;
}
