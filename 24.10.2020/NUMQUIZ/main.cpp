#include <iostream>
#include <cstdio>
using namespace std;
int a[100000];

int MinSeq(int a[], int n) {
    int ans = a[1];
    for (int i = 2; i<=n; i++) {
        if (a[i] < ans)
            ans = a[i];
    }
    return ans;
}

int MaxSeq(int a[], int n) {
    int ans = a[1];
    for (int i = 2; i<=n; i++) {
        if (a[i] > ans)
            ans = a[i];
    }
    return ans;
}

int MinSum(int a[], int n) {
    int mi = MinSeq(a,n), ma = MaxSeq(a,n);
    int sum = 0;
    while (mi != ma) {
        ma = mi;
        for (int i = 1; i<=n; i++) {
            if (a[i] != mi) {
                if (a[i] % mi == 0)
                    a[i] = mi;
                else
                    a[i] = a[i] % mi;
                if (a[i] < mi)
                    mi = a[i];
            }
        }
    }
    return a[1]*n;
}

void ReadData(int a[], int n) {
    for (int i = 1; i<=n; i++) {
        cin >> a[i];
    }
}

int main()
{
    int n;
    freopen("NUMQUIZ.INP", "r", stdin);
    freopen("NUMQUIZ.OUT", "w", stdout);
    cin >> n;
    ReadData(a,n);
    cout << MinSum(a,n);
    return 0;
}
