#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct big
{
    int d[252];
};

big add(big A,big B)
{
    big C;
    memset(C.d,0,sizeof(C.d));
    for (int i = 0; i < 250; i++)
    {
        C.d[i] += A.d[i] + B.d[i];
        if (C.d[i] > 9)
        {
            C.d[i + 1]++;  C.d[i] -= 10;
        }
    }
    return C;
};

big mul(big A,int x)
{
    big C;
    memset(C.d,0,sizeof(C.d));
    for (int i = 0; i < 250; i++) C.d[i] = A.d[i] * x;
    for (int i = 0; i < 250; i++)
    {
        C.d[i + 1] += C.d[i] / 10;  C.d[i] %= 10;
    }
    return C;
}

big assign(int x)
{
    big A;
    memset(A.d,0,sizeof(A.d));
    A.d[0] = x;
    for (int i = 0; i < 12; i++)
    {
        A.d[i + 1] = A.d[i] / 10;  A.d[i] %= 10;
    }
    return A;
}

string s;
int n;
big d10[255],f10[255];
big ret;

void solve()
{
    memset(ret.d,0,sizeof(ret.d));
    for (int dig = 1; dig < 10; dig++)
    {
        big tmp;
        memset(tmp.d,0,sizeof(tmp.d));
        for (int i = n - 1; i > 0; i--)
        {
            big r = mul(f10[i],s[i]);
            tmp = add(tmp,r);  //1st part: lower
            if (s[i] > dig) tmp = add(tmp,d10[i]);
            else if (s[i] == dig)
            {
                big D;
                memset(D.d,0,sizeof(D.d));
                for (int j = 0; j < i; j++) D.d[j] = s[j];
                D.d[0]++;
                tmp = add(tmp,D);
            }
        }
        if (s[0] >= dig) tmp.d[0]++;
        tmp = mul(tmp,dig);
        ret = add(ret,tmp);
    }

    int pos = 249;
    while (!ret.d[pos]) pos--;
    for (int i = pos; i >= 0; i--) printf("%d", ret.d[i]);
    printf("\n");
}
int main()
{
//  freopen("sum.inp","r",stdin);
//  freopen("sum.out","w",stdout);
    cin >> s;
    reverse(s.begin(),s.end());
    n = s.size();
    for (int i = 0; i <= n; i++) s[i] -= '0';
    d10[0] = assign(1);
    for (int i = 1; i <= n; i++) d10[i] = mul(d10[i - 1],10);
    for (int i = 1; i <= n; i++) f10[i] = mul(d10[i - 1],i);
    solve();
}
