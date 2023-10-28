#include <iostream>
#include <cstdio>
using namespace std;
int a[1000000];

void ReadData(int a[], int n) {
    for (int i = 1; i<=n; i++) {
        cin >> a[i];
    }
}

void Min2(int a[], int n, int &min1, int &min2) {
    min1 = a[1];
    if (n < 2) {
        min2 = -1;
        return;
    }
    min2 = a[2];
    if (min2 < min1)
        swap(min1,min2);
    for (int i = 3; i<=n; i++) {
        if ((a[i] < min2) && (a[i] != min1)) {
            min2 = a[i];
        }
        if (min2 < min1)
            swap(min1,min2);
    }
}

int main()
{
    int n, min1, min2;
    freopen("MANG04.INP", "r", stdin);
    freopen("MANG04.OUT", "w", stdout);
    cin >> n;
    ReadData(a,n);
    Min2(a,n,min1,min2);
    cout << min1 << " " << min2;
    return 0;
}
