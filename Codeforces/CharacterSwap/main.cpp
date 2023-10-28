#include <iostream>
#include <bits/stdc++.h>
#define MaxN 50
#define MaxC 26
using namespace std;
typedef pair<int, int> pii;
int k, n, cntNIP[MaxC+1];
string s, t;

void Init() {
    memset(cntNIP, 0, sizeof(cntNIP));
}

void MarkPos() {
    for (int i=0; i<n; i++) {
        if (s[i] != t[i]) {
            cntNIP[s[i] - 'a']++;
            cntNIP[t[i] - 'a']++;
        }
    }
}

void SolveTestCase() {
    vector<pii> Swaps;
    Swaps.clear();
    for (int i=0; i<=MaxC; i++) {
        if (cntNIP[i]%2 == 1) {
            cout << "NO\n";
            return;
        }
    }
    for (int i=0; i<n; i++) {
        if (s[i] != t[i]) {
            int Sh = -1;
            for (int j=i+1; j<n; j++) {
                if (s[i] == s[j]) {
                    Sh = j;
                    break;
                }
            }
            if (Sh == -1) {
                int id = -1;
                for (int j=i+1; j<n; j++) {
                    if (s[i] == t[j]) {
                        id = j;
                        break;
                    }
                }
                Swaps.push_back(pii(id+1, id+1));
                swap(s[id], t[id]);
                Swaps.push_back(pii(id+1, i+1));
                swap(t[i], s[id]);
            }
            else {
                Swaps.push_back(pii(Sh+1, i+1));
                swap(s[Sh], t[i]);
            }
        }
    }
    cout << "YES\n" << Swaps.size() << '\n';
    for (auto x: Swaps)
        cout << x.first << ' ' << x.second << '\n';
}

void Solve() {
    for (int i=1; i<=k; i++) {
        cin >> n >> s >> t;
        Init();
        MarkPos();
        SolveTestCase();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> k;
    Solve();
    return 0;
}
