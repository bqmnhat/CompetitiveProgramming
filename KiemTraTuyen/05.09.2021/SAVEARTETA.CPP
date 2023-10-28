#include <bits/stdc++.h>

using namespace std;
#define FAST		    ios_base::sync_with_stdio(false); cin.tie(NULL);
#define prs(n)		    cout << fixed << setprecision(n)
#define ll			    long long
#define db			    double
#define fo(i,m,n)       for(int i = m; i <= n; i++)
#define fob(i,m,n)      for(int i = n; i >= m; i--)
typedef                 pair<int, int> ii;
typedef                 vector<ii> vii;
typedef                 vector<vii> vvii;
const                   int maxi=INT_MAX;
const                   int _x[] = {-1,-1,-1,0,0,1,1,1};
const                   int _y[] = {-1,0,1,-1,1,-1,0,1};

const int mod=1e9+7, N=2e5+7;

int n, ans, x, h[N], s[N], k[N], sum;

void input()
{
    cin >> n >> x;
    fo(i,0,n-1) cin >> h[i];
    fo(i,0,n-1) cin >> s[i];
    fo(i,0,n-1) cin >> k[i], sum += k[i];

}

void solve()
{
    int dp[sum][2], run=0;
    fo(i,0,sum-1)
    {
        dp[i][0] = h[run];
        dp[i][1] = s[run];
        k[run]--;
        if (k[run] == 0)
            run++;
    }
    int testH, testS;
    fo(i,0,n-1)
    {
        testH = dp[i][0];
        testS = dp[i][1];
        fo(j,0,n-1)
        {
            if (i == j) continue;
            if (testH + dp[i][0] <= x)
            {
                testH += dp[i][0];
                testS += dp[i][1];
                //cout << h[i] <<" ";
            }   else break;
            ans = max(ans,testS);
        }
    }
    cout << ans;
}

int main()
{
    FAST
    freopen("SAVEARTETA.INP", "r", stdin);
    freopen("SAVEARTETA.OUT", "w", stdout);
    int t;
        input();
        solve();
    return 0;
}
