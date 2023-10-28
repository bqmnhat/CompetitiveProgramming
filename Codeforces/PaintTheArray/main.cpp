#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t,n;
long long a[101];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

bool Check(long long val) {
    bool Divi = false, PreDiv;
    if (a[1]%val == 0)
        PreDiv = true;
    else
        PreDiv = false;
    for (int i=2; i<=n; i++) {
        if (a[i] % val == 0)
            Divi = true;
        else
            Divi = false;
        if (Divi == PreDiv)
            return false;
        PreDiv = Divi;
    }
    return true;
}

long long FindGCD(long long a, long long b) {
    long long tmp;
    while (a != 0) {
        tmp = a;
        a = b%a;
        b = tmp;
    }
    return b;
}

long long Solution() {
    long long GCD1 = a[1], GCD2 = a[2];
    int i = 1;
    while (i <= n) {
        GCD1 = FindGCD(GCD1, a[i]);
        i+=2;
    }
    i = 2;
    while (i <= n) {
        GCD2 = FindGCD(GCD2, a[i]);
        i+=2;
    }
    bool Tmp1 = Check(GCD1);
    bool Tmp2 = Check(GCD2);
    if (Tmp1)
        return GCD1;
    else if (Tmp2)
        return GCD2;
    else
        return 0;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        cout << Solution() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
