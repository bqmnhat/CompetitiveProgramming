#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("SONDUONG.inp", "r", stdin);
    freopen("SONDUONG.out", "w", stdout);

    int n, x, y, l , r, maxim = 0;
    cin>>n;
    cin>>x>>y;

    while(n--)
    {
        cin>>l>>r;
        if(maxim<(r-l))
        {
            maxim = (r-l);
        }

    }
    cout<<maxim;
    return 0;
}
