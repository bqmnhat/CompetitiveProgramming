#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n;

int SumOfDig(int x) {
    int ans = 0;
    while (x > 0) {
        ans = ans + x%10;
        x = x/10;
    }
    return ans;
}

int SumOfFac(int n) {
    int m = sqrt(n), i = 2, d, ans = 0;
    while ((i<=m) && (n > 1)) {
        d = 0;
        while (n%i == 0) {
            n = n/i;
            d++;
        }
        ans = ans + (SumOfDig(i)*d);
        i = i + 1;
    }
    if ((n > 1) && (ans > 0)) {
        ans = ans + SumOfDig(n);
    }
    return ans;
}

long long NextSpecial(int n) {
    n = n + 1;
    while (SumOfDig(n) != SumOfFac(n))
        n = n + 1;
    return n;
}

int main()
{
    freopen("NSPECIAL.INP", "r", stdin);
    freopen("NSPECIAL.OUT", "w", stdout);
    cin >> n;
    cout << NextSpecial(n);
    return 0;
}
