#include <bits/stdc++.h>

using namespace std;

int n,x;
vector < pair <long double,int> > v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    freopen("SAVEARTETA.INP", "r", stdin);
    freopen("SAVEARTETA.OUT", "w", stdout);

    cin >> n >> x;

    long double h[n],s[n],k[n],dif[n];
    int dem=0,ans=0;

    for(int i=1 ;i<=n ;i++)
        cin >> h[i];
    for(int i=1 ;i<=n ;i++)
        cin >> s[i];
    for(int i=1 ;i<=n ;i++)
        cin >> k[i];
    for(int i=1;i<=n;i++)
        dif[i]=(s[i]/h[i]);
    for(int i=0;i<n;i++)
    {
        v.push_back( make_pair( dif[i+1],i+1 ) );
    }
    sort(v.begin(),v.end());
    n--;
    while(n>=0)
    {
        if(x > h[v[n].second])
        {
            ans+=s[v[n].second];
            x-= h[v[n].second];
            k[v[n].second]--;
            if( k[v[n].second] == 0)
                n--;
        }
        else
            break;
    }
    cout << ans;

}
