#include <bits/stdc++.h>
using namespace std;

void findDigits(int a, int b)
{
    long long left = 100000000;
    long long right = 100000000;
    long long i;
    double d = 0;
    bool kc = false;
    for(i=1;i<=90000;i++)
    {
        d += log10(i);
        if(floor(d)+1==a)
        {
            left = min(left,i);
            kc = true;
        }
        if(floor(d)+1==b)
        {
            right = i;
            cout << left <<" "<<right;
            return;
        }
        if(floor(d)+1 > a && floor(d)+1>b)
        {
            if(kc==true)
                cout << left<<" "<<i-1;
            else
                cout << i <<" "<<i-1;
            return;
        }
    }
}

int main()
{
    freopen("FACTORIAL.INP","r",stdin);
    freopen("FACTORIAL.OUT","w",stdout);
    int a,b;
    cin >> a>>b;
    findDigits(a,b);
}
