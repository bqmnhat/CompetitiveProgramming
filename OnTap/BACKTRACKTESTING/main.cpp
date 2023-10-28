#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// In tat ca cac day nhi phan do dai n
int n, x[1000001];

void Print() {
    for (int i=1; i<=n; i++) {
        cout << x[i];
    }
    cout << endl;
}

void Try(int i) {
    for (int v = 0; v<=1; v++) {
        x[i] = v;
        if (i == n) {
            Print();
        }
        else
            Try(i+1);
    }
}

int main()
{
    cin >> n;
    Try(1);
    return 0;
}
