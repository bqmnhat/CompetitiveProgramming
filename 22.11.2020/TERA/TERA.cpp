#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long x[1001], d[1001], t[1001], v[1001], xd[1000001], tv[1000001], fxd[1000001], ftv[1000001];
int n,k = 1, k1,k2, L;

void ReadData(long long a[]) {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
}

void GenXdTv() {
    for (int i = 1; i<=n; i++) {
        for(int j = 1; j<=n; j++) {
            xd[k] = x[i] + d[j];
            tv[k] = t[i] + v[j];
            k++;
        }
    }
    k = n*n;
}

void Compress(long long a[], long long fa[], int& k1) {
    int d = 1,c = 0;
    sort(a+1, a+1+k);
    fa[1] = 1;
    for (int i = 2; i<=k; i++) {
        if (a[i] != a[i-1]) {
            ++d;
            a[d] = a[i];
        }
        fa[d]++;
    }
    k1 = d;
}

long long NofSum() {
    long long ans = 0;
    int i = 1, j = k2;
    while ((i<=k1) && (j>=1)) {
        if(xd[i] + tv[j] == L) {
            ans = ans + fxd[i] * ftv[j];
            ++i;
            --j;
        }
        else if (xd[i] + tv[j] < L)
            i++;
        else
            j--;
    }
    return ans;
}

int main()
{
    freopen("TERA.INP", "r", stdin);
    freopen("TERA.OUT", "w", stdout);
    cin >> n >> L;
    ReadData(x);
    ReadData(d);
    ReadData(t);
    ReadData(v);
    GenXdTv();
    Compress(xd, fxd, k1);
    Compress(tv, ftv, k2);
    cout << NofSum();
    return 0;
}
