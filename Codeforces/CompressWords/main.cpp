#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const ll Base = 271, Mod = 1e9 + 11;

string Solution() {
    string ans = "", Next;
    cin >> ans;
    for (int i=2; i<=n; i++) {
        cin >> Next;
        int Lans = ans.length(), LNext = Next.length(), stFromId = 0;
        int MinLen = min(Lans, LNext);
        ll hans = 0, hNext = 0, Rev_Multi = 1;
        for (int i=0; i<MinLen; i++) {
            hans = ((ans[Lans - i - 1]*Rev_Multi)%Mod + hans)%Mod;
            hNext = ((hNext*Base)%Mod + Next[i])%Mod;
            if (hNext == hans)
                stFromId = i+1;
            Rev_Multi = (Rev_Multi*Base)%Mod;
        }
        for (int i = stFromId; i<LNext; i++)
            ans.push_back(Next[i]);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cout << Solution();
    return 0;
}
