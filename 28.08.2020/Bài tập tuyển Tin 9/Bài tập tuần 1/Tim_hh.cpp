#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

bool HHChecker(int n) {
    int sum = 0;
    if (n == 1)
        return true;
    for (int i = 2; i <= int(sqrt(n)); i++) {
        if (n%i == 0) {
            sum = sum + i + int(n/i);
        }
    }
    sum = sum + 1;
    if (int(sqrt(n)) * int(sqrt(n)) == n)
        sum = sum - sqrt(n);
    if (sum == n)
        return true;
    else
        return false;
}

int main()
{
    int n;
    freopen("Tim_hh.inp", "r", stdin);
    freopen("Tim_hh.out", "w", stdout);
    cin >> n;
    if (n > 0) {
        for (int i = 1; i <= n; i++) {
            if (HHChecker(i) == true)
                cout << i << " ";
        }
    }
    return 0;
}
