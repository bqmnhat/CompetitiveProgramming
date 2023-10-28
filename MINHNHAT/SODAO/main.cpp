#include <iostream>
#include <cstdio>
using namespace std;

long long SoDao(int n) {
    long long ans = 0;
    bool am = false;
    if (n < 0) {
        n = n * -1;
        am = true;
    }
    while (n > 0) {
        ans = ans*10 + n%10;
        n = n/10;
    }
    if (am == true)
        return ans * -1;
    return ans;
}

int main()
{
    int n;
    freopen("SODAO.INP", "r", stdin);
    freopen("SODAO.OUT", "w", stdout);
    cin >> n;
    cout << SoDao(n)%19;
    return 0;
}
