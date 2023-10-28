#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t, n, a[200001];
long long tk[200001];
stack<long long> stk;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        tk[a[i]]++;
    }
}

void Init() {
    for (int i=0; i<=n; i++)
        tk[i] = 0;
    while (!stk.empty())
        stk.pop();
}

void SolveTestCases() {
    long long StepTillNow = 0;
    for (int i=0; i<=n; i++) {
        cout << StepTillNow + tk[i] << ' ';
        for (int j=1; j<tk[i]; j++)
            stk.push(i);
        if (tk[i] == 0) {
            if (!stk.empty()){
                StepTillNow += ((1LL*i) - stk.top());
                stk.pop();
            }
            else {
                for (int k = i+1; k<=n; k++)
                    cout << "-1 ";
                return;
            }
        }
    }
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        SolveTestCases();
        cout << '\n';
        Init();
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
