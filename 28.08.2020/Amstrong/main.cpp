#include <iostream>
#include <cstdio>
using namespace std;

int SumOfDigs(int n) {
    int sum = 0, tmp;
    while (n>0) {
        tmp = n%10;
        n = n/10;
        sum = sum + (tmp*tmp*tmp);
    }
    return sum;
}

bool IsAmstrong(int n) {
    if (n == SumOfDigs(n))
        return true;
    else
        return false;
}

int main()
{
    int n;
    freopen("Amstrong.inp", "r", stdin);
    freopen("Amstrong.out", "w", stdout);
    cin >> n;
    if (IsAmstrong(n))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
