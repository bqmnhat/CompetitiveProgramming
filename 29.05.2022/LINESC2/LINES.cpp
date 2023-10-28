#include <iostream>
#include <bits/stdc++.h>
#define MaxN 100000
using namespace std;
typedef pair<int, int> pii;
int dp[MaxN+1], trace[MaxN+1], a[MaxN+1], b[MaxN+1], id[MaxN+1], n, arr[MaxN+1];
vector<int> lis, SeqEnd[MaxN+1];

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        id[a[i]] = i;
    }
    for (int i=1; i<=n; i++) {
        cin >> b[i];
        arr[i] = id[b[i]];
    }
}

void PrintAns(int End, int len) {
    for (int i=1; i<=n; i++)
        sort(SeqEnd[i].begin(), SeqEnd[i].end());
    vector<int> ans;
    ans.clear();
    while (len > 0) {
        ans.push_back(a[End]);
        len--;
        if (len == 0)
            break;
        int j = lower_bound(SeqEnd[len].begin(), SeqEnd[len].end(), End) - SeqEnd[len].begin() - 1;
        End = SeqEnd[len][j];
    }
    sort(ans.begin(), ans.end());
    for (int i: ans)
        cout << i << ' ';
}

void LIS() {
    int ans = 0, AnsEnd;
    for (int i=1; i<=n; i++) {
        int j = upper_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
        dp[i] = j + 1;
        if (dp[i] > ans) {
            ans = dp[i];
            AnsEnd = arr[i];
        }
        SeqEnd[dp[i]].push_back(arr[i]);
        if (j == lis.size())
            lis.push_back(arr[i]);
        else
            lis[j] = arr[i];
    }
    cout << ans << '\n';
    PrintAns(AnsEnd, ans);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("LINES.INP", "r", stdin);
    freopen("LINES.OUT", "w", stdout);
    cin >> n;
    ReadData();
    LIS();
    return 0;
}
