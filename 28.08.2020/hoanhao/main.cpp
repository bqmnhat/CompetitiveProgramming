#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long ll;
int n;

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
    freopen("hoanhao.inp", "r", stdin);
    freopen("hoanhao.out", "w", stdout);
    cin >> n;
    if (HHChecker(n) == true)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
