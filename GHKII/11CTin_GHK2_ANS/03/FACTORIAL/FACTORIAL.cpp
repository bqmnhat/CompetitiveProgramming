#include <bits/stdc++.h>

using namespace std;
long long tinhgiai(int x)
{
    if (x==1) return 1;
    return x*tinhgiai(x-1);
}
long long so(int x)
{
    int a=x,e=0;
    while (a!=0)
    {
       a/=10;
       e++;
    }
    return e;
}
int main()
{
    freopen("FACTORIAL.INP","r",stdin);
    freopen("FACTORIAL.OUT","w",stdout);
    long long m ,n;
    cin>>m>>n;
    long long h=m,t=m;
    for (long long i=m; i<=pow(n,2);i++)
    {
        long long tam=so(tinhgiai(i));
        if (tam>=m && tam<=n)
            t++;
        else if (h != t)
        {
            break;
        }
        else {h++;t++;}
    }
    if (h==t-1)
        cout<<t<<" "<<h;
    else
        cout<<h<<" "<<t-1;
}
