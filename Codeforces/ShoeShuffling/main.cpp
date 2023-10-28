#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
int t, n, s[MaxN+2];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> s[i];
}

void SolveTestCases() {
    vector<int> gr, ans;
    gr.clear();
    s[n+1] = 0;
    bool Found = true;
    for (int i=1; i<=n; i++) {
        if (s[i] != s[i+1]) {
            if (gr.size() == 0) {
                Found = false;
                break;
            }else {
                ans.push_back(i);
                for (auto x: gr)
                    ans.push_back(x);
                gr.clear();
            }
        }
        else
            gr.push_back(i);
    }
    if (!Found) {
        cout << "-1";
        return;
    }
    for (auto x: ans)
        cout << x << ' ';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        SolveTestCases();
        cout << '\n';
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
