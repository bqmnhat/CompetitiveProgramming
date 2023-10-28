#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long GCD(long long a, long long b) {
    long long tmp = 0;
    while (b != 0) {
        tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}

void AddFrac(long long atu, long long amau, long long btu, long long bmau, long long &tu, long long &mau) {
    int msc = (amau*bmau)/GCD(abs(amau), abs(bmau));
    atu = atu * msc/amau;
    btu = btu * msc/bmau;
    tu = atu + btu;
    mau = msc/GCD(abs(tu),abs(msc));
    tu = tu/GCD(abs(tu),abs(msc));
}

int main()
{
    long long atu,amau,btu,bmau,tu,mau;
    freopen("ADD.INP", "r", stdin);
    freopen("ADD.OUT", "w", stdout);
    cin >> atu >> amau >> btu >> bmau;
    AddFrac(atu,amau,btu,bmau,tu,mau);
    cout << tu << " " << mau;
    return 0;
}
