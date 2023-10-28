#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long n;

long long Reverse(long long n) {
    long long ans = 0;
    while (n > 0) {
        ans = ans*10 + (n%10);
        n = n/10;
    }
    return ans;
}

int main()
{
    cin >> n;
    cout << Reverse(n);
    return 0;
}
