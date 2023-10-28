#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
#define MaxC 26
using namespace std;
typedef pair<int, int> pii;
int t, n;
pii cnt[MaxC+5];
string s;

bool CmpSecond(pii a, pii b) {
    return a.second < b.second;
}

void SolveTestCase() {
    for (int i=1; i<=MaxC; i++)
        cnt[i] = pii(0, i);
    for (int i=0; i<n; i++)
        cnt[s[i] - 'a' + 1].first++;
    sort(cnt+1, cnt+1+MaxC, greater<pii>());
    int ans = 1e9, NumOfCInT;
    for (int i=1; i<=26; i++) {
        if (n%i == 0) {
            int tmp = n/i, tmpCost = 0;
            for (int j=1; j<=i; j++)
                tmpCost += max(0, tmp - cnt[j].first);
            if (tmpCost < ans) {
                ans = tmpCost;
                NumOfCInT = i;
            }
        }
    }
    cout << ans << '\n';
    for (int i=1; i<=NumOfCInT; i++)
        cnt[i].first = n/NumOfCInT;
    for (int i=NumOfCInT+1; i<=26; i++)
        cnt[i].first = 0;
    sort(cnt+1, cnt+1+MaxC, CmpSecond);
    for (int i=0; i<n; i++) {
        if (cnt[s[i] - 'a' + 1].first)
            cnt[s[i] - 'a' + 1].first--;
        else
            s[i] = '*';
    }
    for (int i=0; i<n; i++) {
        if (s[i] == '*') {
            for (int j=1; j<=MaxC; j++) {
                if (cnt[j].first) {
                    cnt[j].first--;
                    cout << char(j + 'a' - 1);
                    break;
                }
            }
        }
        else
            cout << s[i];
    }
    cout << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> s;
        SolveTestCase();
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
