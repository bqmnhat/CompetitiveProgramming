#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, t;
string s;
map<ll, int> m;
const ll Base = 31, Mod = 1e12 + 11;

int Solution() {
    int ans = 0;
    m.clear();
    ll Mult = 1, HashVal = 0;
    for (int i=0; i<k-1; i++) {
        HashVal = ((HashVal*Base)%Mod + (s[i] - 'a' + 1))%Mod;
        Mult = (Mult*Base)%Mod;
    }
    HashVal = ((HashVal*Base)%Mod + (s[k-1] - 'a' + 1))%Mod;
    m[HashVal]++;
    ans++;
    for (int i=k; i<n; i++) {
        HashVal = (HashVal - ((s[i-k] - 'a' + 1)*Mult)%Mod + Mod)%Mod;
        HashVal = ((HashVal*Base)%Mod + (s[i] - 'a' + 1))%Mod;
        if (m.find(HashVal) == m.end()) {
            ans++;
            m[HashVal]++;
        }
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> k >> s;
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
