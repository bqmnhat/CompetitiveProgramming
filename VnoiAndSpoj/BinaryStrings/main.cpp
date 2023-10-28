#include <iostream>
#include <bits/stdc++.h>
#define MaxN 300
using namespace std;
typedef bitset<MaxN> Num;
int n, m, k;
Num s[MaxN+1];
unordered_set<Num> a;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> s[i];
        a.insert(s[i]);
    }
}

bool Check(const Num& x1, const Num& x2, const Num& x3) {
    Num ans = ((x1&x2) | (x2&x3) | (x1&x3));
    return a.count(ans);
}

void Solve() {
    if (k == 1) {
        cout << "YES";
        return;
    }
    bool IsBeauty = true;
    for (int i=1; i<=n-2; i++) {
        for (int j=i+1; j<=n-1; j++) {
            for (int t=j+1; t<=n; t++) {
                if (!Check(s[i], s[j], s[t])) {
                    IsBeauty = false;
                    break;
                }
            }
        }
    }
    if (IsBeauty)
        cout << "YES";
    else
        cout << "NO";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    ReadData();
    Solve();
    return 0;
}
