#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long n;

long long sqr(long long x) {
    return ((x%1000000007)*(x%1000000007))%1000000007;
}

long long Solution(int a, long long b) {
    if (b == 0) return 1;
    else
        if (b % 2 == 0)
            return sqr(Solution(a, b/2) % 1000000007)%1000000007;
        else
            return a * sqr(Solution(a, (b-1)/2) % 1000000007)%1000000007;
}

int main()
{
    cin >> n;
    cout << Solution(2,n) - 1;
    return 0;
}
