#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define int long long
#define pii pair<int, int>
int fact(int n)
{
    if( n == 0) return 1;
    else return n * fact(n-1);
}

int counting(int n)
{
    int tmp = n, res =0;
    while(tmp!=0)
    {
        tmp/=10;
        res+=1;
    }
    return res;
}
void solve(int m,int n)
{
    int tmp = m, check = m;
    for(int i = m; i<=n*n; i++)
    {
        int t = counting(fact(i));
        if(t>=m && t <=n) check++;
        else{
            if(check!=tmp)
            {
                check--;
                break;
            }
            else
            {
                check++; tmp++;
            }
        }
    }
    if(check == tmp) cout<< n+1<<" "<< n;
    else cout<<tmp<< " " <<check;
}
signed main()
{
    freopen("FACTORIAL.inp","r",stdin);
    freopen("FACTORIAL.out","w",stdout);
    int m,n;
    cin>>m>>n;
    solve(m,n);
}
