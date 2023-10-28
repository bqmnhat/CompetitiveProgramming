#include <iostream>
#include <cstdio>
using namespace std;
int a[1000000];

void ReadData(int a[], int n) {
    for (int i = 1; i<=n; i++) {
        cin >> a[i];
    }
}

void Solve(int n, int a[], int &pos1, int &pos2) {
    int min1,min2;
    min1 = a[1];
    pos1 = 1;
    if (n < 2) {
        pos2 = -1;
        return;
    }
    min2 = a[2];
    pos2 = 2;
    if (min2 < min1) {
        swap(min1,min2);
        swap(pos1,pos2);
    }
    for (int i=3; i<=n; i++) {
        if (a[i] < min2) {
            min2 = a[i];
            pos2 = i;
        }
        if (min2 < min1) {
            swap(min1,min2);
            swap(pos1,pos2);
        }
    }
}

int main()
{
    int n, pos1, pos2;
    freopen("MANG05.INP", "r", stdin);
    freopen("MANG05.OUT", "w", stdout);
    cin >> n;
    ReadData(a,n);
    Solve(n,a,pos1,pos2);
    cout << pos1 << " " << pos2;
    return 0;
}
