#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int a[40001], n, m;

void PrintKQ() {
    for(int i=1; i<=n; i++) {
        cout << a[i];
    }
    cout << endl;
}

bool Bang(int i, int k) {
    for (int j = 0; j<=k-1; j++) {
        if (a[i-j] != a[i-k-j])
            return false;
    }
    return true;
}

bool Chuan(int i) {
    int t = i/2;
    for(int k = 1; k<=t; k++) {
        if (Bang(i,k) == true) {
            return false;
        }
    }
    return true;
}

int Tim(int i) {
    while (a[i] < m) {
        a[i]++;
        if (Chuan(i) == true)
            return a[i];
    }
    return -1;
}

void TimTu() {
    int i = 1, k;
    while (true) {
        if  (i>n) {
            PrintKQ();
            i--;
        }
        if (i < 1)
            return;
        k = Tim(i);
        if (k>0) {
            a[i] = k;
            i++;
        }
        else {
            a[i] = 0;
            i--;
        }
    }
}

int main()
{
    freopen("TUCHUAN.INP", "r", stdin);
    freopen("TUCHUAN.OUT", "w", stdout);
    cin >> n >> m;
    TimTu();
    return 0;
}
