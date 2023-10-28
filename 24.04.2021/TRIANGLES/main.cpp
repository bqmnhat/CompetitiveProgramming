#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long x[300001], freqx[300001], freqy[300001], y[300001];
int TotalY = 0, n, nx, ny;

void ReadData() {
    for (int i = 1; i<=n; i++) {
        cin >> x[i] >> y[i];
    }
}

void Compress(long long a[], long long freqa[], int &na) {
    int k=0, i = 1, dem = 1;
    while (i <= n) {
        if (a[i] != a[i+1]) {
            k++;
            freqa[k] = dem;
            a[k] = a[i];
            dem = 1;
            i++;
        }
        else {
            dem++;
            i++;
        }
    }
    na = k;
}

long long CountTri() {
    long long ans = 0;
    for (int i=1; i<=ny; i++) {
        TotalY += freqy[i];
    }
    for (int i=1; i<=nx; i++) {
        ans = ans + (freqx[i]-1)*(TotalY - ny);
    }
    return ans;
}

int main()
{
    freopen("TRICOUNT.INP", "r", stdin);
    freopen("TRICOUNT.OUT", "w", stdout);
    cin >> n;
    ReadData();
    sort(x+1,x+1+n);
    sort(y+1,y+1+n);
    Compress(x, freqx, nx);
    Compress(y, freqy, ny);
    cout << CountTri();
    return 0;
}
