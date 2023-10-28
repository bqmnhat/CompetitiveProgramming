#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool a[200000];
int k;

void MakeSieve() {
    int m = 447;
    a[0] = a[1] = true;
    for (int i=2; i<=m; i++) {
        if (a[i] == false) {
            for (int j=i; j<=200000/i; j++) {
                a[i*j] = true;
            }
        }
    }
}

bool IsPrime(long long val) {
    long long m = sqrt(val);
    if ((val%6 == 1) or (val%6 == 5)) {
        for (int i=2; i<=m; i++) {
            if (val%i==0)
                return false;
        }
        return true;
    }
    else
        return false;
}

void Find500() {
    int dem = 0, i = 2;
    long long so1,so2;
    long long val;
    long long Power = 10;
    while (dem < k) {
        while (a[i] == true) i++;
        so1 = i;
        i++;
        if (so1 >= Power)
            Power = Power*10;
        while (a[i] == true) i++;
        so2 = i;
        i++;
        val = so1*Power+so2;
        if (IsPrime(val)) {
            dem++;
        }
    }
    cout << val;
}

int main()
{
    freopen("MPRIME.INP", "r", stdin);
    freopen("MPRIME.OUT", "w", stdout);
    MakeSieve();
    cin >> k;
    Find500();
    return 0;
}
