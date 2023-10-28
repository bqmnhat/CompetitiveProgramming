#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e6;
int t, TotalDiv[1000001];
long long SumDiv[1000001];

void MakeTotalDiv() {
    int m = sqrt(MaxN);
    for (int i=1; i<=m; i++) {
        TotalDiv[i*i]++;
        for (int j = i+1; i*j<=MaxN; j++)
            TotalDiv[i*j] += 2;
    }
    for (int i=1; i<=MaxN; i++)
        TotalDiv[i] = TotalDiv[i-1] + TotalDiv[i];
}

void MakeSumDiv() {
    int m = sqrt(MaxN);
    for (int i=1; i<=m; i++) {
        SumDiv[i*i] += (long long)i;
        for (int j = i+1; j<=MaxN; j++)
            SumDiv[i*j] += (long long)(i+j);
    }
    for (int i=1; i<=MaxN; i++)
        SumDiv[i] = SumDiv[i-1] + SumDiv[i];
}

void SolveTestCases() {
    int a, b;
    for (int i=1; i<=t; i++) {
        cin >> a >> b;
        cout << TotalDiv[b] - TotalDiv[a-1] << ' ' << SumDiv[b] - SumDiv[a-1] << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("DIVISORS.INP", "r", stdin);
    freopen("DIVISORS.OUT", "w", stdout);
    cin >> t;
    MakeTotalDiv();
    MakeSumDiv();
    SolveTestCases();
    return 0;
}
