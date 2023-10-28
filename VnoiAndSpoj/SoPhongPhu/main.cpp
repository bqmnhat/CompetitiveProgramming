#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
int l, r;
ll d[MaxN+5];

void MakeD() {
    for (int x=1; x*x <= MaxN; x++) {
        d[x*x] += 1LL*x;
        for (int y=x+1; x*y<=MaxN; y++)
            d[x*y] += 1LL*x + 1LL*y;
    }
}

int Solution() {
    int res = 0;
    for (int i=l; i<=r; i++)
        if (d[i]-1LL-1LL*i > 1LL*i)
            res++;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> l >> r;
    MakeD();
    cout << Solution();
    return 0;
}
