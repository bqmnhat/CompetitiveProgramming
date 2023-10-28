#include <iostream>
#include <cstdio>
using namespace std;
int a[1000000];

void Solve(int a[], int n) {
    cout << a[1] << " ";
    for (int i = 2; i<=n; i++) {
        if (a[i] < a[i-1])
            cout << endl;
        cout << a[i] << " ";
    }
}

void ReadData(int a[], int n) {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

int main()
{
    int n;
    freopen("MANG07.INP", "r", stdin);
    freopen("MANG07.OUT", "w", stdout);
    cin >> n;
    ReadData(a,n);
    Solve(a,n);
    return 0;
}
