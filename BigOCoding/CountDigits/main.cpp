#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string n;
bool DevideEvenly[10];
int l;

bool IsDivideByN(ll x) {
    ll p = 1, TotalMod = 0;
    for (int i=l-1; i>=0; i--) {
        ll val = n[i] - '0';
        TotalMod = ((TotalMod%x)+ ((p%x)*(val%x))%x)%x;
        p = ((p%x)*(10%x))%x;
    }
    return (TotalMod == 0);
}

int Solution() {
    int ans = 0;
    for (int i=1; i<10; i++)
        DevideEvenly[i] = IsDivideByN(i);
    for (int i=0; i<l; i++)
        if (DevideEvenly[n[i] - '0'])
            ans++;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    l = n.length();
    cout << Solution();
    return 0;
}
