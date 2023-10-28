#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n = 1000000;

void gen() {
    cout << n << endl;
    for (int i = 1; i<=n; i++) {
        int a = rand() %2000000000 + 1;
        cout << a << " ";
    }
}

int main()
{
    freopen("COUNT_FI.INP", "w", stdout);
    gen();
    return 0;
}
