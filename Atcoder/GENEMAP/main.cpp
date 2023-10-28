#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef long long ll;
int n, k;
ll Mod = 1e9 + 7;
string s[MaxN+1], RevS[MaxN+1];
map<string, ll> m1;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> s[i];
}

ll Solution() {
    ll ans = 0;
    for (int i=1; i<=n; i++) {
        int l = s[i].length();
        string tmp = "";
        for (int j=0; j<l && j<k; j++)
            tmp = tmp + s[i][j];
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    ReadData();
    MakeFreq();
    cout << Solution();
    return 0;
}
