#include <iostream>

using namespace std;

int GT(int x)
{
    int g = 1;
    for (int i = 1; i <= x; i++)
        g += i;
    return g;
}
int m (int x)
{
    int cnt = 1;
    if (x < 10)
    {
        cnt = 1;
        return cnt;
    }
    else
    {
        while (x >= 10)
        {
            x /= 10;
            ++cnt;
        }
        return cnt;
    }
}

int main()
{
    freopen("FACTORIAL.INP","r",stdin)
    freopen("FACTORIAL.OUT","w",stdout);
    int m, n;
    cin>>m>>n;
    for (int i = m; i <= n*100000; ++i)
        if
    cout << "Hello world!" << endl;
    return 0;
}
