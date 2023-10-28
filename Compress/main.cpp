#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[100001], val[100001], freq[100001], l, n;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

void Compress() {
    sort(a+1, a+1+n);
    int d = 1,k = 1;
    val[1] = a[1];
    freq[1] = 1;
    for (int i = 2; i<=n; i++) {
        if (a[i] != a[i-1]) {
            ++k;
            val[k] = a[i];
        }
        freq[k] = freq[k] + 1;
    }
    l = k;
}

void Print() {
    for (int i = 1; i<=l; i++) {
        cout << val[i] << " " << freq[i] << endl;
    }
}

int main()
{
    freopen("INPUT.INP","r", stdin);
    freopen("OUTPUT.OUT", "w", stdout);
    cin >> n;
    ReadData();
    Compress();
    Print();
    return 0;
}
