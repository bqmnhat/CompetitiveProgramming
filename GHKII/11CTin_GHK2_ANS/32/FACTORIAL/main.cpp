#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define MaxN 1000007

int digit[MaxN], m, n;
double log_num[MaxN];
void solve()
{
    int left=0, right=0;
    for(int i = 1; i <= MaxN; ++i)
    {
        log_num[i] = log_num[i - 1] + log10(i);
        digit[i] = log_num[i] + 1;
        if(digit[i] >= m && left == 0)
            left = i;
        if(digit[i] > n && right == 0)
        {
            right = i-1;
            break;
        }
    }
    cout<<left<<" "<<right;
}
int main()
{
    freopen("FACTORIAL.INP", "r", stdin);
    freopen("FACTORIAL.OUT", "w", stdout);
    cin >> m >> n;
    solve();
    return 0;
}
