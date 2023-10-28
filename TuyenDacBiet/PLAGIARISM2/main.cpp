#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int m = 1e9+7;
int p = 31, k, x;
ll p_pows[200001], p_powt[200001];
string s, t;
vector<ll> hs, ht;

vector<ll> HashVal(string const& s, ll p_pow[]) {
    int l = s.length();
    vector<ll>hash_value(l+1, 0);
    p_pow[1] = 1;
    for (int i = 1; i<=l; i++) {
        hash_value[i] = (hash_value[i-1] + (s[i-1] - 'A' + 1) * p_pow[i]) % m;
        p_pow[i+1] = (p_pow[i] * p) % m;
    }
    return hash_value;
}

bool Check(int len) {
    int l = s.length();
    set<ll> M;
    for (int i=1; i<=l; i++)
        M.insert(((hs[i+len-1] - hs[i-1])/p_pows[i])%m);
    int l2 = t.length();
    for (int i=1; i<=l2; i++) {
        ll tmp = ((ht[i+len-1] - ht[i-1])/p_powt[i])%m;
        if (M.find(tmp) != M.end())
            return true;
    }
    return false;
}

int MaxLenght() {
    int l = 0 , r = min(s.length(),t.length());
    while (l <= r){
        int mid = l + (r-l)/2;
        if(Check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l-1;
}

int main()
{
    cin >> k >> x >> s >> t;
    hs = HashVal(s, p_pows);
    ht = HashVal(t, p_powt);
    cout << MaxLenght();
    return 0;
}
