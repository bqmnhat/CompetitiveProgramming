/*
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/
#include<bits/stdc++.h>
using namespace std;
int64_t mod=1e9+7;
vector<int> dsu,siz;
int get (int u) {
    while (u!=dsu[u]) u=dsu[u];
    return u;
}
int main (){
    ios::sync_with_stdio(0);cin.tie(0);
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    int n,m;cin>>n>>m;
    int64_t fact[n+1];
    fact[0]=1;
    for (int i=1;i<=n;i++) fact[i]=fact[i-1]*i%mod;
    dsu.resize(n);
    siz.resize(n,1);
    for (int i=0;i<n;i++) dsu[i]=i;
    for (int i=0;i<m;i++) {
        int x,y;cin>>x>>y;
        dsu[x]=get(x);x=dsu[x];
        dsu[y]=get(y);y=dsu[y];
        if (x!=y) {
            if (siz[x]>siz[y]) {
                dsu[y]=x;
                siz[x]+=siz[y];
            }
            else {
                dsu[x]=y;
                siz[y]+=siz[x];
            }
        }
    }
    vector<bool> mark(n);
    int64_t sol=0;
    for (int i=0;i<n;i++) {
        int j=get(i);
        if (mark[j]) continue;
        mark[j]=true;
        if (siz[j]>2) sol = ((sol%mod) + (fact[siz[j]]%mod))%mod;
    }
    cout<<sol%mod<<'\n';
    return 0;
}
