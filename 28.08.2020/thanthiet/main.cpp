#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int SumFactors(int n) {
    int sum = 1;
    for (int i = 2; i <= int(sqrt(n)); i++) {
        if (n%i == 0) {
            sum = sum + i + int(n/i);
        }
    }
    if (int(sqrt(n)) * int(sqrt(n)) == n)
        sum = sum - sqrt(n);
    return sum;
}

int Thanthiet(int n) {
    int tmp = SumFactors(n);
    if ((SumFactors(tmp) == n) && (tmp != n))
        return tmp;
    else
        return -1;
}

int main()
{
    int n;
    freopen("thanthiet.inp", "r", stdin);
    freopen("thanthiet.out", "w", stdout);
    cin >> n;
    if (Thanthiet(n) > 0)
        cout << Thanthiet(n);
    else
        cout << "NO";
    return 0;
}
