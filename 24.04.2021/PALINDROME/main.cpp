#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;

void PrintPalin(int left, int k) {
    cout << left;
    if (k%2 == 1) {
        left = left/10;
    }
    int a;
    while (left > 0) {
        a = left%10;
        left = left/10;
        cout << a;
    }
}

void Solve() {
    long long dem = 9, k = 1;
    while (n - dem > 0) {
        n = n - dem;
        k++;
        if (k%2 == 1) {
            dem = dem*10;
        }
    }
    long long p = dem/9;
    long long left = p + n-1;
    PrintPalin(left, k);
}

int main()
{
    freopen("PALINDROME.INP", "r", stdin);
    freopen("PALINDROME.OUT", "w", stdout);
    cin >> n;
    Solve();
    return 0;
}
