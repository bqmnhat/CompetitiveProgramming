#include <bits/stdc++.h>
using namespace std;

int gthua(int n)
{
    if (n==0) return 1;
    return n*gthua(n-1);
}

int Count(int n)
{
        int a=n,ans=0;
        while(a!=0)
        {
            a=a/10;
            ans=ans+1;
        }
        return ans;
}

int main ()
{
    ifstream fi;
    ofstream fo;
    fi.open("FACTORIAL.INP");
    fo.open("FACTORIAL.OUT");
    long long n,m;
    cin>>m>>n;
    long long Start=m, End=m;
    for (long long i=m; i<=n*n;i++)
    {
    long long h=Count(gthua(i));
    if (h>=m && h<=n) End=End+1;
    else
    {
        if (End!=Start)
        {
            End--;
            break;
        }
        else
        {
            End++;
            Start++;
        }
    }
    }
    if (Start==End) cout<<n+1<<" "<<n;
    else cout<<Start<<" "<<End;
}
