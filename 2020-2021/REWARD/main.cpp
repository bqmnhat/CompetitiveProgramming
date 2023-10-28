#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, x, y;
int xx[5] = {0,0,-1,0,1}, yy[5] = {0,-1,0,1,0}, guide[500001], gl = 0, gsl = 0;
long long Gset[500001];
string s;

void MakeGuide() {
    for (int i=0; i<s.length(); i++) {
        gl++;
        if (s[i] == 'W') {
            guide[gl] = 1;
        }
        else if (s[i] == 'N') {
            guide[gl] = 2;
        }
        else if (s[i] == 'E') {
            guide[gl] = 3;
        }
        else {
            guide[gl] = 4;
        }
    }
}

int BinSearch(long long val) {
    int lo = 1, hi = gsl;
    while (lo <= hi) {
        int m = (lo+hi)/2;
        if (Gset[m] == val) {
            return 1;
        }
        else if (Gset[m] > val) {
            hi = m - 1;
        }
        else
            lo = m + 1;
    }
    return 0;
}

long long CalVal(int x, int y) {
    int k = x+y-1;
    if (k <= n) {
        if (k%2 == 0) {
            long long v = ((k*(k+1))/2);
            return v-y+1;
        }
        else {
            long long v = ((k*(k-1))/2 + 1);
            return v+y-1;
        }
    }
    else {
        k = abs(k-2*n);
        if (k%2 == 0) {
            long long v = (n*n) - ((k*(k-1))/2);
            return v-y+(n-k+1);
        }
        else {
            long long v = (n*n) - ((k*(k+1))/2 - 1);
            return v+y-(n-k+1);
        }
    }
}

long long Reward() {
    long long ans = CalVal(x,y);
    gsl++;
    Gset[gsl] = ans;
    for (int i=1; i<=gl; i++) {
        x += xx[guide[i]];
        y += yy[guide[i]];
        int val = CalVal(x,y);
        if (BinSearch(val) == 0) {
            gsl++;
            Gset[gsl] = val;
            ans += val;
            sort(Gset+1, Gset+1+gsl);
        }
    }
    return ans;
}

int main()
{
    freopen("REWARD.INP", "r", stdin);
    freopen("REWARD.OUT", "w", stdout);
    cin >> n >> x >> y >> s;
    MakeGuide();
    cout << Reward();
    return 0;
}
