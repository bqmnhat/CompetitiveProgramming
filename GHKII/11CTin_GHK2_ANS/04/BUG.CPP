#include <bits/stdc++.h>
using namespace std;
int n, x[10001], y[10001], a[10001], b[10001], ans=0, res=0,minstep=100007,maxstep=-100007,pos[1000007];
bool flag=true;
pair<int,int> bug[10005];

bool ktkenhau(){
    for(int i=1;i<=n-1;i++){
        if(abs(a[i]-a[i+1])!=1){return false;}
    }
    return true;
}

int main()
{
    freopen("BUG.INP","r",stdin);
    freopen("BUG.OUT","w",stdout);
    cin>>n;
    for(int i=0;i<=100007;i++){
        pos[i]=0;
    }
    for(int i=1;i<=n;i++){
        cin>>bug[i].first>>bug[i].second;
        bug[i].first+=10000;
        bug[i].second+=10000;
        if(bug[i].first<minstep)minstep=bug[i].first;
        if(bug[i].first>maxstep)maxstep=bug[i].first;
        pos[bug[i].first]++;
    }
    int num;

    for(int i=1;i<=n;i++){
        if(flag)res+=abs(sum/n-bug[i].second);
        else res+=abs(num/n+1-bug[i].second);
    }
    for(int i=1;i<=n;i++){
        if(pos[bug[i].first]>1)
        {
            if(maxstep==minstep)res+=i-1;
            else if)bug[i].first-minstep>maxstep)res+=abs(maxstep-bug[i].first);
            else res+=abs(minstep-bug[i].first);
        }
    }
    cout<<res;
}

