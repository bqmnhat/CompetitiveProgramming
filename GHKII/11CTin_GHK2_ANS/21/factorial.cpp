#include <bits/stdc++.h>
using namespace std;

long long giaithua(int n)
{
    if (n==0) return 1;
    return n*giaithua(n-1);
}

int demchuso(int n)
{
    int a=n, kq=0;
    while (a!=0)
    {
        a/=10;
        kq+=1;
    }
    return kq;
}

int main()
{
freopen("FACTORIAL.inp","r",stdin);
freopen("FACTORIAL.out","w",stdout);
    int n,m;
    cin>>m>>n;
    long long bd = m, kt = m;
    for (long long i=m; i<=n*n; i++)
    {
        long long t = demchuso(giaithua(i));
        if (t>=m && t<=n)
        {
            kt+=1;
        }
        else
        {
            if (kt!=bd)
            {
                kt--;
                break;
            }
            else
            {
                kt++;
                bd++;
            }
        }
    }
    if (bd==kt) cout<<n+1<<" "<<n;
    else cout<<bd<<" "<<kt;
    return 0;
}
