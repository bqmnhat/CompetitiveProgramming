#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

bool IsPrime(int n) {
    if (n==1)
        return false;
    if (n<=0)
        return false;
    for (int i = 2; i <= int(sqrt(n)); i++) {
        if (n%i == 0)
            return false;
    }
    return true;
}

bool IsStrong(int x) {
    for (int i = 2; i <= int(sqrt(x)); i++) {
        if ((IsPrime(i)) && (x%(i*i) == 0)) {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    freopen("STRONG.INP", "r", stdin);
    freopen("STRONG.OUT", "w", stdout);
    cin >> n;
    for (int i = 2; i <= n; i++) {
        if (IsStrong(i))
            cout << i << " ";
    }
    return 0;
}
