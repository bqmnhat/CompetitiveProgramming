#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
using namespace std;
int a[MaxN+1], n, t, MarkMask[2*MaxN+1], MaxSOS[2*MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

int SolutionSub1() {
    int ans = 0;
    bool Exist1[205], Exist2[205];
    for (int i=1; i<=n; i++) {
        memset(Exist1, false, sizeof(Exist1));
        int tmp1 = 0;
        for (int k=i; k<=n; k++) {
            if (Exist1[a[k]])
                break;
            tmp1++;
            Exist1[a[k]] = true;
            ans = max(ans, tmp1);
            for (int j=k+1; j<=n; j++) {
                memset(Exist2, false, sizeof(Exist2));
                int tmp2 = 0;
                for (int t=j; t<=n; t++) {
                    if ((Exist2[a[t]]) || (Exist1[a[t]]))
                        break;
                    tmp2++;
                    Exist2[a[t]] = true;
                    ans = max(ans, tmp1 + tmp2);
                }
            }
        }
    }
    return ans;
}

int SolutionSub2() {
    memset(MarkMask, 0, sizeof(MarkMask));
    memset(MaxSOS, 0, sizeof(MaxSOS));
    int ans = 0;
    for (int i=1; i<=n; i++) {
        int mask = 0;
        for (int j=i; j<=min(i+19, n); j++) {
            if (mask&(1<<(a[j]-1)))
                break;
            mask = (mask^(1 << (a[j] - 1)));
            MarkMask[mask] = __builtin_popcount(mask);
        }
    }
    for (int mask=0; mask<(1 << 20); mask++)
        MaxSOS[mask] = MarkMask[mask];
    for (int k=0; k<20; k++)
        for (int mask = 0; mask < (1 << 20); mask++)
            if (mask&(1 << k))
                MaxSOS[mask] = max(MaxSOS[mask], MaxSOS[mask^(1 << k)]);
    int tmp = (1 << 20) - 1;
    for (int mask=0; mask<(1 << 20); mask++) {
        if (MarkMask[mask] == 0)
            continue;
        int CurMaskBitCnt = MarkMask[mask];
        ans = max(ans, CurMaskBitCnt +  MaxSOS[tmp^mask]);
    }
    return ans;
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n;
        ReadData();
        if (n <= 200)
            cout << SolutionSub1();
        else
            cout << SolutionSub2();
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
