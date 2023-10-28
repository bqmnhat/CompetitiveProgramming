#include<iostream>
#include<bits/stdc++.h>
#define MaxN 100000
#define MaxVal 1000000
using namespace std;
typedef long long ll;
int n, a[MaxN+5];
ll mo[MaxVal+5], cnt[MaxVal+5], cntMult[MaxVal+5], Fact[MaxN+5], InvFact[MaxN+5];

void ReadData() {
    for (int i=1; i<=n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
}

ll nC3(ll n) {
    if (n<3)
        return 0;
    ll deno = n*(n-1LL)*(n-2);
    ll ans = deno/6;
    return ans;
}

void MakeMo() {
    mo[1] = 1;
    for (int i=1; i<=MaxVal; i++)
        for (int j=2*i; j<=MaxVal; j+=i)
            mo[j] -= mo[i];
}

void CountMultOfAll() {
    for (int i=1; i<=MaxVal; i++) {
        int j = i;
        while (j<=MaxVal) {
            cntMult[i] += cnt[j];
            j+=i;
        }
    }
    for (int i=1; i<=MaxVal; i++)
        cntMult[i] = nC3(cntMult[i]);
}

ll CntExclusionSize() {
    ll ans = 0;
    for (int i=2; i<=MaxVal; i++)
        ans += cntMult[i]*(-1LL)*mo[i];
    return ans;
}

ll Solution() {
    ll ExclSize = CntExclusionSize();
    ll ans = nC3(n) - ExclSize;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    MakeMo();
    cin >> n;
    ReadData();
    CountMultOfAll();
    cout << Solution();
    return 0;
}
