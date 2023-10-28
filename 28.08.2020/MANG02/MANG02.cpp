#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int a[1000000];

void ReadA(int n, int a[]) {
    for (int i = 1; i<=n; i++) {
        cin >> a[i];
    }
}

int MinDiff(int n, int a[]) {
    int tmp = abs(a[2] - a[1]);
    for (int i = 3; i<=n; i++){
        int m = abs(a[i] - a[i-1]);
        if (m<tmp) {
            tmp = m;
        }
    }
    return tmp;
}

int main()
{
    int n;
    freopen("MANG02.INP", "r", stdin);
    freopen("MANG02.OUT", "w", stdout);
    cin >> n;
    ReadA(n,a);
    cout << MinDiff(n,a);
    return 0;
}
