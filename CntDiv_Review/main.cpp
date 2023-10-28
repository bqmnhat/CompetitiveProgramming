#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
typedef long long ll;
int d[MaxN+1];
ll n;
map <int, int> mu;

void MakeD() {
    for (int i=2; i*i<=MaxN; i++)
        if (d[i] == 0)
            for (int j = 1; i*j <= MaxN; j++)
                d[i*j] = i;
}

ll CntDiv(int n) {
    mu.clear();
    ll ans = 1;
    while (n > 1) {
        int p = d[n];
        if (p == 0)
            p = n;
        mu[p]++;
        n = n/p;
    }
    for (auto i: mu)
        ans = 1LL*ans*(i.second*1LL + 1LL);
    return ans;
}

int main()
{
    MakeD();
    cin >> n;
    cout << CntDiv(n);
    return 0;
}
