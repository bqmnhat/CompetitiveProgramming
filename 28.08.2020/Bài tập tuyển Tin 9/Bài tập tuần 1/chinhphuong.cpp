#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int n;
    freopen("chinhphuong.inp","r", stdin);
    freopen("chinhphuong.out", "w", stdout);
    cin >> n;
    if (n >= 0) {
        if (int(sqrt(n)) * int(sqrt(n)) == n)
            cout << "Yes";
        else
            cout << "No";
    }
    return 0;
}
