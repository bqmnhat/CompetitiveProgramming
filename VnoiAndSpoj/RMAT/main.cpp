#include <iostream>
#include <bits/stdc++.h>
#define MaxN 1000000
#define MaxDp 42
using namespace std;
typedef long long ll;
int n, m;
ll SumOfCol[MaxN], SumOfRow[MaxN];
vector<vector<ll>> a;

void ReadData() {
    a.assign(n, vector<ll>(m, 0));
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> a[i][j];
}

void CalSumOfCol() {
    for (int j=0; j<m; j++)
        for (int i=0; i<n; i++)
            SumOfCol[j] += a[i][j];
}

void CalSumOfRow() {
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            SumOfRow[i] += a[i][j];
}

int UntilNotMod2(ll val) {
    int ans = 0;
    while ((val > 0) && (val % 2 == 0)) {
        ans++;
        val >>= 1LL;
    }
    return ans;
}

ll NoMore2(ll val) {
    while ((val > 0) && (val%2 == 0))
        val >>= 1LL;
    return val;
}

int MaxCombination(const vector<int>& a) {
    int len = a.size();
    if (a[0] == -1)
        return len - 1;
    vector<vector<int>> dp(len+10, vector<int>(MaxDp+1, -1));
    vector<int> dp2(len+10, 0);
    for (int i = 0; i<len; i++)
        dp[i][a[i]] = i;
    for (int x = 1; x<=MaxDp; x++) {
        for (int i=0; i<len; i++) {
            if ((dp[i][x-1] == -1) || (dp[dp[i][x-1] + 1][x-1] == -1))
                continue;
            dp[i][x] = dp[dp[i][x-1] + 1][x-1];
        }
    }
    for (int i=len-1; i>=0; i--) {
        int tmp = dp2[i+1];
        for (int x = 0; x<=MaxDp; x++)
            if (dp[i][x] != -1)
                tmp = max(tmp, dp[i][x] - i + dp2[dp[i][x] + 1]);
        dp2[i] = tmp;
    }
    return dp2[0];
}

bool CheckSameY(ll val, ll y) {
    if (y == 0)
        return (val == 0);
    if (val < 0LL)
        val = (-1LL)*val;
    ll tmp = UntilNotMod2(val);
    val = val/(1LL << tmp);
    return (val == y);
}

bool CheckSameSign(ll val1, ll val2) {
    return (((val1 >= 0LL) && (val2 >= 0LL)) || ((val1 < 0LL) && (val2 < 0LL)));
}

int ArrayCombination(ll Arr[MaxN], int len) {
    vector<int> tmp;
    int i = 0, ans = len;
    while (i < len) {
        tmp.clear();
        ll val = Arr[i];
        if (val < 0LL)
            val = (-1LL)*val;
        int First = UntilNotMod2(val);
        ll FirstArr = Arr[i];
        if (val == 0)
            tmp.push_back(-1);
        else
            tmp.push_back(First);
        ll y = val/(1LL << (1LL*First));
        i++;
        while ((i < len) && (CheckSameY(Arr[i], y)) && (CheckSameSign(Arr[i], FirstArr))) {
            ll val = Arr[i];
            if (val < 0LL)
                val = (-1LL)*val;
            if (val == 0)
                tmp.push_back(-1);
            else
                tmp.push_back(UntilNotMod2(val));
            i++;
        }
        ans -= MaxCombination(tmp);
    }
    return ans;
}

int Solution() {
    int SolForCol = ArrayCombination(SumOfCol, m), SolForRow = ArrayCombination(SumOfRow, n);
    return (SolForCol * SolForRow);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    ReadData();
    CalSumOfCol();
    CalSumOfRow();
    cout << Solution();
    return 0;
}
