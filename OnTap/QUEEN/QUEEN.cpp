#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int m, n;
long long a[1001][1001], sumhor[1001], sumver[1001], sumdiag1[2000], sumdiag2[2000];

void ReadData() {
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    }
}

void MakeHor() {
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            sumhor[i] += a[i][j];
        }
    }
}

void MakeVer() {
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            sumver[i] += a[j][i];
        }
    }
}

void MakeDiag1() {
    int i, j;
    for (int t=1; t<=m; t++) {
        i = t;
        j = 1;
        while ((i>=1) && (j<=n)) {
            sumdiag1[i+j-1] += a[i][j];
            i--;
            j++;
        }
    }
    for (int t=2; t<=n; t++) {
        i = m;
        j = t;
        while ((i>=1) && (j<=n)) {
            sumdiag1[i+j-1] += a[i][j];
            i--;
            j++;
        }
    }
}

void MakeDiag2() {
    int i, j;
    for (int t=m; t>=1; t--) {
        i = t;
        j = 1;
        while ((i<=m) && (j<=n)) {
            sumdiag2[j-i+m] += a[i][j];
            i++;
            j++;
        }
    }
    for (int t=2; t<=n; t++) {
        i = 1;
        j = t;
        while ((i<=m) && (j<=n)) {
            sumdiag2[j-i+m] += a[i][j];
            i++;
            j++;
        }
    }
}

long long Solution() {
    long long ans = -1e12, tmp;
    for (int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            tmp = sumhor[i] + sumver[j] + sumdiag1[i+j-1] + sumdiag2[j-i+m] - 3*a[i][j];
            if (tmp > ans)
                ans = tmp;
        }
    }
    return ans;
}

int main()
{
    freopen("QUEEN.INP", "r", stdin);
    freopen("QUEEN.OUT", "w", stdout);
    cin >> m >> n;
    ReadData();
    MakeHor();
    MakeVer();
    MakeDiag1();
    MakeDiag2();
    cout << Solution();
    return 0;
}
