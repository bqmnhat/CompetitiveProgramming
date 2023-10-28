#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("DDB.INP", "w", stdout);
    cout << 10001 << endl;
    srand(time(NULL));
    for (int i=1; i<=10000; i++) {
        int m = rand() % (1000000 - 1 + 1) + 1;
        cout << m << endl;
    }
    cout << 1000000 << endl;
    return 0;
}
