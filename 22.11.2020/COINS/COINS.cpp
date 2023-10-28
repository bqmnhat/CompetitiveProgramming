#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,m;
struct to {
    int a,b;
}x[100001];

void ReadData() {
    for (int i = 1; i<=n; i++) {
        cin >> x[i].a;
    }
    for (int i = 1; i<=n; i++) {
        cin >> x[i].b;
    }
}

bool CompareA(to a,to b) {
    if ((a.b - a.a) == (b.b - b.a))
        return (a.b >= b.b);
    else
        return ((a.b - a.a) <= (b.b - b.a));
}

int Coins() { // mode = 1: sort theo a; mode = 0: sort theo b;
    int k = m,i = 1;
    sort(x+1,x+1+n,CompareA);
    while (i<=n) {
        if (k >= x[i].b - x[i].a){
            k = k + x[i].a;
        }
        i += 1;
    }
    return k;
}

int main()
{
    freopen("COINS.INP", "r", stdin);
    freopen("COINS.OUT", "w", stdout);
    cin >> n >> m;
    ReadData();
    cout << Coins();
    return 0;
}
