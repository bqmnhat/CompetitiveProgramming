#include <bits/stdc++.h>
using namespace std;

int giaithua(int n)
{
 if(n==0){return 1;}
 return n*giaithua(n-1);
}

int demchuso(int n)
{
    int a=n, kq=0;
    while (a!=0)
           {
               a=a/10;
                kq=kq+1;
           }
    return kq;
}

int main()
{
    ifstream fi;
    ifstream fo;
    fi.open("FACTORIAL.inp");
    fo.open("FACTORIAL.out");
    long long n,m;
    cin>>m>>n;
    long long bd=m , kt=m;
    for(long long i=m; i<=n*n; i++)
      {
       long long t=demchuso(giaithua(i));
       if(t>=m && t<=n)
        {
            kt=kt+1;
        }
        else
        {
            if (kt!=bd)
            {
                kt--;
                break;
            }
            else {kt++; bd++;}
        }
      }
    if (bd==kt){cout<<n+1<<" "<<n;}
    else{cout<<bd<<" "<<kt;}
}
