#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
int n, SumFactors[MaxN+5], d[MaxN+5], AnsNum[MaxN+5], cntNum = 0;

void MakeSumFactors() {
    for (int x=1; x*x <= MaxN; x++) {
        SumFactors[x*x]++;
        for (int y=x+1; x*y<=MaxN; y++)
            SumFactors[x*y] += 2;
    }
}

void MakeD() {
    for (int i=2; i*i<=MaxN; i++)
        if (d[i] == 0)
            for (int j=i; i*j<=MaxN; j++)
                d[i*j] = i;
}

void FindAllAnsNumm() {
    for (int i=1; i<=MaxN; i++) {
        int p = d[SumFactors[i]];
        if (p == 0)
            continue;
        int q = SumFactors[i]/p;
        if ((d[q] != 0) || (q == p))
            continue;
        cntNum++;
        AnsNum[cntNum] = i;
    }
}

void Solve() {
    for (int i=9; i<=cntNum; i+=9)
        cout << AnsNum[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    MakeSumFactors();
    MakeD();
    FindAllAnsNumm();
    Solve();
    return 0;
}
