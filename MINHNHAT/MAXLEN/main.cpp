#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[1001][1001], n;

int MaxHor() {
    int ans = 0,tmp;
    for (int i=1;i<=n; i++) {
        tmp = 0;
        for (int j=1; j<=n; j++) {
            tmp += a[i][j]
        }
        if (tmp > ans)
            ans = tmp;
    }
    return ans;
}

int MaxHor() {
    int ans = 0,tmp;
    for (int j=1;j<=n; j++) {
        tmp = 0;
        for (int i=1; i<=n; i++) {
            tmp += a[i][j]
        }
        if (tmp > ans)
            ans = tmp;
    }
    return ans;
}

int MaxRLDiag() {
    int ans = 0, tmp;
    for (int i=1;i<=n; i++) {
        tmp = 0;
        int x=i, y=1;
        while ((x<=i) && (y>=0)) {//
            tmp += a[x][y];
            x--;//
            y++;//
        }
        if (tmp>ans)
            ans = tmp;
    }
    for (int i=2;i<=n; i++) {
        tmp = 0;
        int x=i, y=n;
        while ((x<=n) && (y>=i)) {//
            tmp += a[x][y];
            x++;//
            y--;//
        }
        if (tmp>ans)
            ans = tmp;
    }
}

int MaxLRDiag() {
    int ans = 0, tmp;
    for (int i=2;i<=n; i++) {//
        tmp = 0;
        int x=i, y=1;
        while (x<=n) {
            tmp += a[x][y];
            x++;//
            y++;//
        }
        if (tmp>ans)
            ans = tmp;
    }
    for (int i=1;i<=n; i++) {//
        tmp = 0;
        int x=1, y=i;
        while (y<=n) {
            tmp += a[x][y];
            x++;//
            y++;//
        }
        if (tmp>ans)
            ans = tmp;
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
