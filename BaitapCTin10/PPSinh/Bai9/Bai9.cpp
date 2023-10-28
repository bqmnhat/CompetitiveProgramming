#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string a;

void Reverse(int x, int y) {
    int i = x, j = y;
    while (i <= j) {
        swap(a[i], a[j]);
        i++;
        j--;
    }
}

bool NextPermutation() {
    int i = a.length()-1;
    while ((i >= 0) && (a[i] > a[i+1]))
        i--;
    if (i < 1)
        return false;
    int j = a.length()-1;
    while (a[j] < a[i])
        j--;
    swap(a[i], a[j]);
    Reverse(i+1,a.length()-1);
    return true;
}

void PrintPermutation() {
    cout << a << '\n';
}

void Solve() {
    PrintPermutation();
    while (NextPermutation())
        PrintPermutation();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("Bai9.OUT", "w", stdout);
    a = "IIIIMPPSSSS";
    Solve();
    return 0;
}
