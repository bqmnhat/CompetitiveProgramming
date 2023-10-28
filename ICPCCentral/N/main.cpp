/*
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
*/
#include<bits/stdc++.h>
using namespace std;
int main (){
    ios::sync_with_stdio(0);cin.tie(0);
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    string s,t;cin>>s>>t;
    int n=s.size(),m=t.size();
    vector<vector<int>> pos(26);
    vector<int> freq(26);
    for (int i=0;i<m;i++) freq[t[i]-'a']++;
    for (int i=0;i<n;i++) pos[s[i]-'a'].push_back(i);
    vector<int> curpos;
    curpos.push_back(-1);
    for (int i=0;i<26;i++) {
        if (freq[i]==0) continue;
        if ((int)pos[i].size()<freq[i]) {
            cout<<"-1\n";
            return 0;
        }
        int l=0,r=(int)curpos.size()-1;
        while (l<r) {
            int mid=(l+r+1)/2;
            int k=upper_bound(pos[i].begin(),pos[i].end(),curpos[mid])-pos[i].begin();
            if ((int)pos[i].size()-k>=freq[i]) l=mid;
            else r=mid-1;
        }
        int k=upper_bound(pos[i].begin(),pos[i].end(),curpos[l])-pos[i].begin();
        for (int j=0;j<freq[i];j++) curpos.push_back(pos[i][k+j]);
        sort(curpos.begin(),curpos.end());
    }
    for (int i=1;i<(int)curpos.size();i++) cout<<s[curpos[i]];
    cout<<'\n';
    return 0;
}
