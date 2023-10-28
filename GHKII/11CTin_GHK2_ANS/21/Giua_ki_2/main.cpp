#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("BUG.INP","r",stdin);
    freopen("BUG.OUT","w",stdout);
    int n,a[10001],b[10001];
    cin>>n;
    int tongx = 0, tongy = 0, demx = 0, demy = 0;
    for (int i = 0; i<n; i++)
    {
        cin>>a[i]>>b[i];
        tongx +=a[i];
        tongy +=b[i];
    }
    int diemdeny = (tongy/n);
    int res = abs(diemdeny - b[0]);
    sort(a,a+n);
    for (int i = 1; i<n; i++)
    {
        res+=abs(diemdeny - b[i]);
        res+=a[i]-(a[0]+i);
    }
    cout<<res;
    return 0;
}
