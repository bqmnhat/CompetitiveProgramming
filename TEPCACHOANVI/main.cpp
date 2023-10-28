#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[12],n;

void Make() {
    for (int i=1; i<=n; i++) {
        a[i] = i;
    }
}

void Reverse(int p1) {
    int i = p1, j=n;
    while(i<j) {
        swap(a[i], a[j]);
        i++;
        j--;
    }
}

void Print() {
    for (int i=1; i<=n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

bool Next() {
    int i=n;
    while ((a[i] >= a[i+1]) && (i>=1)) {
        i--;
    }
    if (i == 0)
        return false;
    int j=n;
    while (a[j] <= a[i]) {
        j--;
    }
    swap(a[i], a[j]);
    Reverse(i+1);
    Print();
    return true;
}

void Solve() {
    while (Next() == true) {
        continue;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    Make();
    Print();
    Solve();
    return 0;
}
