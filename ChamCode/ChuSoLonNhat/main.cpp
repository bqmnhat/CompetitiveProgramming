#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long n;

long long MaxDig(long long n) {
    long long ans = 0;
    while (n > 0) {
        if ((n%10) > ans)
            ans = n%10;
        n = n/10;
    }
    return ans;
}

int main()
{
    cin >> n;
    cout << MaxDig(n);
    return 0;
}
