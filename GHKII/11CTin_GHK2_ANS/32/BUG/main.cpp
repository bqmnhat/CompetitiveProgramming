#include <bits/stdc++.h>

using namespace std;
#define MaxN 10007

pair<int, int> a[MaxN];
bool visted[MaxN];
int sum_y = 0, n, avr, dp[MaxN][2];
vector<int> num;
void solve()
{

}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i].first >> b[i].second;
        if(visited[a[i].first])
        {
            num.push_back(a[i].first);
            continue;
        }
        visited[a[i].first] = true;
        sum_y += a[i].second;
    }
}
