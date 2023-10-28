#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100005
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int> L, R, Num;
int ConId;
const ll Mod = 1e9 + 7;

void ReadData() {
    string s1, s2;
    cin >> s1 >> s2;
    while (s1.length() < s2.length())
        s1 = '0' + s1;
    int l1 = s1.length(), l2 = s2.length();
    for (int i=0; i<l1; i++)
        L.push_back(s1[i] - '0');
    for (int i=0; i<l2; i++)
        R.push_back(s2[i] - '0');
}

void CalPref() {
    int LOfR = R.size();
    for (int i=0; i<LOfR; i++) {
        if (L[i] == R[i])
            Num.push_back(L[i]);
        else {
            ConId = i;
            break;
        }
    }
}

ll Solution() {
    CalPref();
    int LOfR = R.size();
    bool MinusOrNot = false;
    for (int i=ConId+1; i<LOfR; i++) {
        if (R[i] < 9) {
            MinusOrNot = true;
            break;
        }
    }
    int tmpId = ConId;
    if (MinusOrNot) {
        while ((tmpId < LOfR) && (R[tmpId] - 1 <= 0))
            tmpId++;
        if (tmpId < LOfR) {
            Num.push_back(R[tmpId] - 1);
            ConId = tmpId;
        }
    }
    else
        Num.push_back(R[ConId]);
    ConId++;
    for (int i=ConId; i<LOfR; i++)
        Num.push_back(9);
    ll ans = 1;
    for (ll x: Num)
        ans = (ans*x)%Mod;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ReadData();
    cout << Solution();
    return 0;
}
