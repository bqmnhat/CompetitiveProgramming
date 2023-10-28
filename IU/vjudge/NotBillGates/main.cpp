#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int q, n;
string s;
vector<int> pos[257];

void FindAllPos(string s) {
    for (int i=0; i<257; i++)
        pos[i].clear();
    for (int i=0; i<n; i++)
        pos[s[i]].push_back(i);
}

void Query(string s1) {
    int i, j = -1, st, ed, l = s1.length();
    for (i=0; i<l; i++) {
        auto tmp = upper_bound(pos[s[i]].begin(), pos[s[i]].end(), j);
        if (tmp == pos[s[i]].end())
            break;
        else {
            int tmpj = int(tmp - pos[s[i]].begin());
            j = pos[s[i]][tmpj];
        }
        if (i == 0)
            st = j;
    }
    ed = j;
    if (i < l)
        cout << "Not matched\n";
    else
        cout << "Matched " << st << ' ' << ed << '\n';
}

void Solve() {
    cin >> q;
    for (int i=1; i<=q; i++) {
        cin >> s;
        Query(s);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    n = s.length();
    FindAllPos(s);
    Solve();
    return 0;
}
