#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
const ll Base1 = 31;
const ll Mod1 = 1e9 + 7;
const ll Base2 = 37;
const ll Mod2 = 1e12 + 7;
unordered_map<ll, int> um;
int k, n, MaxLen = 0;
ll powOfB2[MaxN+5];
string a[55];
vector<ll> h[55];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        MaxLen = max(MaxLen, (int)a[i].length());
    }
}

vector<ll> GenHash(string s, ll Base, ll Mod, ll powOfB[MaxN+5], bool MakePow) {
    int l = s.length();
    vector<ll> h(l+1, 0);
    powOfB[0] = 1;
    for (int i=1; i<=l; i++) {
        h[i] = (h[i-1]*Base + (s[i-1] - 'A' + 1))%Mod;
        if (MakePow)
            powOfB[i] = (powOfB[i-1]*Base)%Mod;
    }
    return h;
}

ll GetHash(const vector<ll>& h, ll Base, ll Mod, ll powOfB[MaxN+5], int l, int r) {
    return (h[r] - (h[l-1]*powOfB[r-l+1])%Mod + Mod)%Mod;
}

bool Check(int len) {
    um.clear();
    for (int i=1; i<=n; i++) {
        int l = a[i].length();
        unordered_map<ll, bool> PutIn;
        PutIn.clear();
        for (int j=1; j+len-1<=l; j++) {
            ll HashVal = GetHash(h[i], Base2, Mod2, powOfB2, j, j+len-1);
            if (PutIn.find(HashVal) == PutIn.end()) {
                um[HashVal]++;
                PutIn[HashVal] = true;
            }
            if (um[HashVal] >= k)
                return true;
        }
    }
    return false;
}

int BinSearch() {
    int lo = 1, hi = MaxLen, ans = 0;
    while (lo <= hi) {
        int mid = ((lo + hi) >> 1);
        if (Check(mid)) {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    return ans;
}

ll Solution() {
    for (int i=1; i<=n; i++) {
        bool flag = false;
        if (i == 1)
            flag = true;
        h[i] = GenHash(a[i], Base2, Mod2, powOfB2, flag);
    }
    return BinSearch();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("PLAGIARISM2.INP", "r", stdin);
    freopen("PLAGIARISM2.OUT", "w", stdout);
    cin >> n >> k;
    ReadData();
    cout << Solution();
    return 0;
}
