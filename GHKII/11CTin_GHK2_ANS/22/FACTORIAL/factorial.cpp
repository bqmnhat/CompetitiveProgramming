#include <bits/stdc++.h>
using namespace std;

int m, n;

int scs(int o)
{
    return (int)floor(log10(o)+1);
}

bool check(int o)
{
    if (o==0)
        return false;
    int cs=scs(o)
}
int bs(int l, int r)
{
    if (l>r)
        return -1;
    int m = (l+r)/2;
    if (kt(m))
    {
        int kq = bs(l, m-1);
        if (kq!=-1)
            return kq;
        return m;
    }
    else
        return bs(m+1, r);
}

int main()
{
    freopen("factorial.inp","r",stdin);
    freopen("factorial.out","w",stdout);

    cin >> m >> n;

    int gt=1;
    while(scs(gt)<=n)
        gt=gt*2;
    int a = bs(0, gt);
    int b = bs(a, gt);
    if (a==1 || b==-1)
        cout << "-1 -1" << "\n";
    else
        cout <<
    return 0;
}
