#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    if (n > 0) {
        freopen("Tim_cp.inp", "r", stdin);
        freopen("Tim_cp.out", "w", stdout);
        cin >> n;
        for (int i = 1; i <= int(sqrt(n)); i++) {
            cout << i*i << " ";
        }
        return 0;
    }
}
