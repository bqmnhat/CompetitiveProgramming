#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int SumFactors(int n) {
    int sum = 0;
    for (int i = 1; i <= int(sqrt(n)); i++) {
        if (n%i == 0) {
            sum = sum + i + int(n/i);
        }
    }
    if (int(sqrt(n)) * int(sqrt(n)) == n)
        sum = sum - sqrt(n);
    return sum;
}

int main()
{
    int n;
    freopen("Sum_u.inp", "r", stdin);
    freopen("Sum_u.out", "w", stdout);
    cin >> n;
    cout << SumFactors(n);
    return 0;
}
