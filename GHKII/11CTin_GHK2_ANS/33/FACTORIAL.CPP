#include<bits/stdc++.h>
#include<cmath>
using namespace std;

void findDigits(int a,int b)
{
    int left = 100000,right = 100000;

    double d = 0;
    bool ExistCase = false;
    for(int i=1;i<=27000;i++)
    {
        d += log10(i);
        if(floor(d)+1 == a)
        {
            left = min(left,i);
            ExistCase = true;
        }
        if(floor(d)+1 == b)
        {
            right = i;
            cout<<left<<" "<<right;
            return;
        }
        if(floor(d)+1 > a && floor(d)+1 > b)
        {
            if(ExistCase == true) cout<<left<<" "<<i-1;
            else cout<<i<<" "<<i-1;
            return;
        }
    }
}
int main()
{
    freopen("FACTORIAL.INP","r",stdin);
    freopen("FACTORIAL.OUT","w",stdout);

    int a,b;
    cin>>a>>b;
    findDigits(a,b);

}

