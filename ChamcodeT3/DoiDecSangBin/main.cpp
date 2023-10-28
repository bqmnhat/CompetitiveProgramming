#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int bin[65], lb = 0;

void PrintBin() {
    for (int i=lb; i>=1; i--) {
        cout << bin[i];
    }
}

void Solve() {
    if (n == 0) {
        cout << "0";
        return;
    }
    while (n > 0) {
        lb++;
        bin[lb] = n%2;
        n = n/2;
    }
    PrintBin();
}

int main()
{
    cin >> n;
    Solve();
    return 0;
}
