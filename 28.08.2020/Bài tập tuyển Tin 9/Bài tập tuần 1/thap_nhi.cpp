#include <iostream>
#include <cstdio>
using namespace std;
int a[100];
void DecToBin(int n) {
    int a[100];
    int l = 0;
    if (n == 0) {
        cout << 0;
        return;
    }
    if (n == 1) {
        cout << 1;
        return;
    }
    while (n > 0) {
        a[l] = n%2;
        n = n/2;
        l = l + 1;
    }
    l = l - 1;
    for (int i = l; i>=0; --i) {
        cout << a[i];
    }
}

int main()
{
    int n;
    freopen("thap_nhi.inp", "r", stdin);
    freopen("thap_nhi.out", "w", stdout);
    cin >> n;
    DecToBin(n);
    return 0;
}
