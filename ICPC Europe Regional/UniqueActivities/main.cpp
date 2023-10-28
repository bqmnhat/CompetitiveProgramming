#include <iostream>
#include <bits/stdc++.h>
#define mod 1000000777
#define d 31
using namespace std;
long long hash_a[300001], mul[300001];
string a;
pair<long long,long long> mark[300001];

long long mi(long long x)
{
    int p = mod - 2;
    int s = 1;
    while (p != 1) {
        if (p % 2 == 1)
            s = ((s%mod) * (x%mod)) % mod;
        x = ((x%mod) * (x%mod)) % mod;
        p /= 2;
    }
    return ((s%mod) * (x%mod)) % mod;
}

void genHash()
{
    mul[0] = 1;
    hash_a[0] = (a[0] - 'A' + 1)%mod;
    for (int i = 1; i < a.length(); i++) {
        mul[i] = (mul[i - 1]*d) % mod;
        hash_a[i] = (hash_a[i - 1] + mul[i]*(a[i] - 'A' + 1)) % mod;
    }
}

int CountLen(int len) {
    for (int i=0; i<=300000; i++) {
        mark[i].first = 0;
        mark[i].second = i;
    }
    mark[0].first = hash_a[len - 1];
    for (int i=1; i<a.length(); i++) {
        int x = (hash_a[i + len - 1] - hash_a[i - 1] + 2*mod)%mod;
        x = (x * mi(mul[i])) % mod;
        mark[i].first = x;
    }
    sort(mark, mark + 300000);
    int i = 1;
    if (mark[0].first != mark[1].first)
        return mark[0].second;
    while (i <= 300000) {
        if ((mark[i].first != mark[i-1].first) && (mark[i].first != mark[i+1].first))
            return mark[i].second;
        i++;
    }
    return -1;
}

void Solve() {
    int lo = 1, hi = a.length(), st, AnsLen;
    while (lo <= hi) {
        int len = (lo + hi)/2;
        int tmp = CountLen(len);
        if (tmp != -1) {
            st = tmp;
            AnsLen = len;
            hi = len - 1;
        }
        else
            lo = len + 1;
    }
    for (int i=st; i<=(st + AnsLen - 1); i++)
        cout << a[i];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a;
    genHash();
    Solve();
    return 0;
}
