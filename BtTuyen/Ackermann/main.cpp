#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int m,n;

int Ackermann(int n, int m) {
    if (n == 0)
        return m+1;
    if (m == 0)
        return Ackermann(n-1,1);
    return Ackermann(n-1, Ackermann(n,m-1));
}

int main()
{
    cin >> n >> m;
    cout << Ackermann(n,m);
    return 0;
}
