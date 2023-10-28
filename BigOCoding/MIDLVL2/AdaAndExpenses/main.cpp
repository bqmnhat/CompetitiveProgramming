#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int Digits[2000001], Mod = 1e9 + 7, l;
ll d[2000001];

void SplitIntoDigits() {
    for (int i=0; i<l; i++)
        Digits[i+1] = int (s[i] - '0');
}

void MakeD() {
    d[1] = 1;
    for (int i = 2; i<=l; i++)
        d[i] = ((d[i-1]*10)%Mod + 1)%Mod;
}

ll Solution() {
    ll ans = 0;
    for (int i=1; i<=l; i++)
        ans = ((ans%Mod) + ((1LL*(i%Mod)*(d[l-i+1]%Mod)*(Digits[i]%Mod))%Mod))%Mod;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    l = s.length();
    SplitIntoDigits();
    MakeD();
    cout << Solution();
    return 0;
}
