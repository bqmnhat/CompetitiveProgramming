#include <bits/stdc++.h>
using namespace std;

const int MAXN=1e6+5;
int m, n, ansa=1e18, ansb=1e18;
int factorial[MAXN], num_digits[MAXN];

void precompute()
{
    factorial[0]=1;
    for(int i=1; i<=n; i++)
    {
        factorial[i]=factorial[i-1]*i;
        int temp=factorial[i];
        int cnt=0;
        while(temp>0)
        {
            cnt++;
            temp/=10;
        }
        num_digits[i]=cnt;
    }
}

void find_range(int k, int &a, int &b)
{
    int lo=0, hi=n;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(num_digits[mid]>=k)
        {
            b=mid;
            hi=mid-1;
        }
        else
            lo=mid+1;
    }
    lo=0, hi=n;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(num_digits[mid]<=k)
        {
            a=mid;
            lo=mid+1;
        }
        else
            hi=mid-1;
    }
}

void Solve()
{
    int lo=0, hi=n;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        int a=1e18, b=-1e18;
        find_range(mid, a, b);
        if(b-a>=m)
        {
            ansa=a;
            ansb=b;
            hi=mid-1;
        }
        else
            lo=mid+1;
    }
}
int main()
{
    freopen("FACTORIAL.INP", "r", stdin);
    freopen("FACTORIAL.OUT", "w", stdout);
    cin>>m>>n;
    precompute();
    Solve();
    if(ansa>ansb)
        cout<<"-1\n";
    else
        cout<<ansa<<" "<<ansb<<"\n";
    return 0;
}
