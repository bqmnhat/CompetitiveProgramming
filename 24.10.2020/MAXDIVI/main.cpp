#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int a[1000000];

void ReadData(int a[], int &l) {
    int i = 0;
    int a1,ax;
    cin >> a1;
    while (cin >> ax) {
        i = i + 1;
        a[i] = abs(ax - a1);
    }
    l = i;
}

int UCLN(int a,int b) {
    int tmp;
    while (b != 0) {
        tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}

int MaxDivi(int a[], int l) {
    int ans = UCLN(a[1],a[2]);
    for (int i = 3; i<=l; i++) {
        ans = UCLN(ans, a[i]);
    }
    return ans;
}

int main()
{
    int l;
    freopen("MAXDIVI.INP", "r", stdin);
    freopen("MAXDIVI.OUT", "w", stdout);
    ReadData(a,l);
    cout << MaxDivi(a,l);
    return 0;
}
