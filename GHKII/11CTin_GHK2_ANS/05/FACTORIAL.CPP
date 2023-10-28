#include <bits/stdc++.h>

using namespace std;
long long solve(int n)
{
    if (n == 0) return 1;
    else return n*solve(n-1);
}
int Counter(int n)
{
    int res = 0;
    while (n!=0)
    {
        n/=10;
        res++;
    }
    return res;
}
int main()
{
    freopen("FACTORIAL.INP","r",stdin);
    freopen("FACTORIAL.OUT","w",stdout);
    long long n,m;
    cin >> m >> n;
    long long op = m, ed = m;
    for (long long i = m;i<=n*n;i++)
    {
        long long time = Counter(solve(i));
        if (time >= m && time <= n)
            ed++;
        else if (ed != op)
        {
            ed--;
            break;
        }
        else
        {
            ed++;
            op++;
        }
    }
    if (op == ed) cout << 2 << ' ' << 1;
    else cout << op << ' ' << ed;
    return 0;
}
