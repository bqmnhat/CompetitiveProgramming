#include <iostream>
#include <bits/stdc++.h>
#define MaxN 30
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
int n, n1, n2;
pii FirstHalf[MaxN+5], SecondHalf[MaxN+5], Sum1[50000], Sum2[50000], UV;
map<pii, int> ExistSecondHalf;

void ReadData() {
    n1 = n/2;
    n2 = n-n1;
    for (int i=0; i<n1; i++)
        cin >> FirstHalf[i].first >> FirstHalf[i].second;
    for (int i=0; i<n2; i++)
        cin >> SecondHalf[i].first >> SecondHalf[i].second;
    cin >> UV.first >> UV.second;
}

pii SumFromMask(int mask, pii Half[MaxN+5]) {
    pii ans = pii(0,0);
    int cnt = -1;
    while (mask > 0) {
        cnt++;
        if (mask&1LL) {
            ans.first += Half[cnt].first;
            ans.second += Half[cnt].second;
        }
        mask >>= 1LL;
    }
    return ans;
}

void FindSums() {
    for (int mask=0; mask < (1 << n1); mask++)
        Sum1[mask] = SumFromMask(mask, FirstHalf);
    for (int mask=0; mask < (1 << n2); mask++) {
        pii tmp = SumFromMask(mask, SecondHalf);
        ExistSecondHalf[tmp]++;
    }
}

int Solution() {
    int res = 0;
    for (int mask=0; mask < (1 << n1); mask++) {
        pii RemainingMask = pii(UV.first - Sum1[mask].first, UV.second - Sum1[mask].second);
        int tmp = ExistSecondHalf[RemainingMask];
        res+=tmp;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ReadData();
    FindSums();
    cout << Solution();
    return 0;
}
