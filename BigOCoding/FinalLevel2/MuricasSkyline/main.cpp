#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, h[5001], w[5001], LIS[5001], LDS[5001], t;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> h[i];
    for (int i=1; i<=n; i++) {
        cin >> w[i];
        LIS[i] = LDS[i] = w[i];
    }
}

void SolveTestCase(int CaseNo) {
    int AnsForLIS = 0, AnsForLDS = 0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            if (h[i] > h[j])
                LIS[i] = max(LIS[i], LIS[j] + w[i]);
            if (h[i] < h[j])
                LDS[i] = max(LDS[i], LDS[j] + w[i]);
            AnsForLIS = max(AnsForLIS, LIS[i]);
            AnsForLDS = max(AnsForLDS, LDS[i]);
        }
    }
    cout << "Case " << CaseNo << ". ";
    if (AnsForLIS >= AnsForLDS)
        cout << "Increasing (" << AnsForLIS << "). Decreasing (" << AnsForLDS << ").";
    else
        cout << "Decreasing (" << AnsForLDS << "). Increasing (" << AnsForLIS << ").";
    cout << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        SolveTestCase(i);
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
