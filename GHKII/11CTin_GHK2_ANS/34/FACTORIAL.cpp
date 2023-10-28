#include <bits/stdc++.h>
using namespace std;

void solve(int a, int b)
{
    long long left=1e9, right=1e9; double d=0; bool kc=false;
    for(long long i=1;i<=900000;i++)
    {
        d+=log10(i);
        if(floor(d)+1==a)
        {
            left=min(left,i);
            kc=true;
        }
        if(floor(d)+1==b)
        {
            right=i;
            cout << left << " " << right;
            return;
        }
        if(floor(d)+1>a&&floor(d)+1>b)
        {
            if(kc) cout << left << " " << i-1;
            else cout << i << " " << i-1;
            return;
        }
    }
}

int main()
{
    freopen("FACTORIAL.inp","r",stdin);
    freopen("FACTORIAL.out","w",stdout);
    int a,b;
    cin >> a >> b;
    solve(a,b);
}
