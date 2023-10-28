#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long a1[21], a2[21], x1[2000000], x2[2000000], Sum = 0, pow2[20];
int n, b1[21], b2[21],m1,m2;

void Init() {
    pow2[0] = 1;
    for (int i=1; i<=20; i++) {
        pow2[i] = pow2[i-1]*2;
    }
}

void ReadData() {
    m1 = n/2;
    m2 = n - m1;
    for (int i=0; i<m1; i++) {
        cin >> a1[i];
    }
    for (int i=0; i<m2; i++) {
        cin >> a2[i];
    }
}

void Next(int a[], int b[], int n) {
    int i=0;
    while ((b[i] != 0) && (i<=n)) {
        b[i] = 0;
        Sum = Sum - a[i];
        i++;
    }
    b[i] = 1;
    Sum = sum + a[i];
}

void MakeX(int a[], int b[], int n, int x[]) {
    for (int i = 0; i<pow2[n]; i++) {
        x[i] = Sum;
        Next(a,b,n);
    }
}

int Lower(int val, int n) {
    int lo = 0, hi = pow2[n]-1;
    while (lo <= hi) {
        int m = (lo+hi)/2;

    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
