#include <iostream>
#include <cstdio>
using namespace std;
int a[1000000];

void ReadA(int n, int a[]) {
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
}

int FactInSeq(int x, int a[], int n) {
    int tmp = 0;
    for (int i = 1; i<=n; i++) {
        if (a[i] != 0){
            if (x%a[i] == 0)
                tmp += 1;
        }
    }
    return tmp;
}

int main()
{
    int x,n;
    freopen("MANG01.INP", "r", stdin);
    freopen("MANG01.OUT", "w", stdout);
    cin >> n >> x;
    ReadA(n,a);
    cout << FactInSeq(x,a,n);
    return 0;
}
