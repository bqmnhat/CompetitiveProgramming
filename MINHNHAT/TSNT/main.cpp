#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void Factorise(int n) {
    int i = 2, m = sqrt(n);
    while ((i<=m) && (n>1)) {
        int d = 0;
        while (n%i == 0) {
            d++;
            n = n/i;
        }
        for (int j = 1; j<=d; j++)
            cout << i << " ";
        i++;
    }
    if (n>1)
        cout << n;
}

int main()
{
    Factorise(14);
    return 0;
}
