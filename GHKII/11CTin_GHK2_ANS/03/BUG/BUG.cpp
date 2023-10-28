#include <iostream>

using namespace std;

int main()
{
    freopen("BUG.INP","r",stdin);
    freopen("BUG.OUT","w",stdout);
    pair<int,int> v[10001];
    int a[10001];
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i].first;
        int d=abs(v[i].first);
        a[d]++;
        if(a[d]>1) a[d]--;
        else
        {
            cin>>v[i].second;
        }
    }
}
