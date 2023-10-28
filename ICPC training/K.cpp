#include <bits/stdc++.h>
using namespace std;
long long base = 31;
const int Maxn = 3e5 + 10;
const long long Mod = 1e9 + 777;
long long Hash[Maxn];
long long p[Maxn];
string s;
int n;
long long getHash(int l, int r){
    return (Hash[r] - Hash[l-1] * p[r-l+1] + Mod * Mod) % Mod;
}
bool check(int length){
    map <long long, int> d;
    for(int i = 1;i <= n - length + 1;i++){
        long long cur = getHash(i, i + length - 1);
        d[cur]++;
    }
    for(auto x : d){
        if(x.second == 1){
            return true;
        }
    }
    return false;
}
void Out(int length){
    map <long long,int > d;
    for(int i = 1; i <= n - length + 1;i++){
        long long cur = getHash(i, i + length - 1);
        d[cur]++;
    }
    for(int i = 1; i <= n - length + 1;i++){
        long long cur = getHash(i, i + length - 1);
        if(d[cur] == 1){
            for(int j = i;j <= i + length - 1;j++)
                cout<<s[j];
            return;
        }
    }
}

int main()
{
    // freopen("1.txt", "r", stdin);

    cin>>s;
    n = s.size();
    s = '.' + s;
    p[0] = 1;
    for(int i = 1;i <= n;i++){
        Hash[i] = (Hash[i-1] * base + s[i]) % Mod;
        p[i] = p[i-1] * base % Mod;
    }
    int l = 1, r = n;
    int ans = n;
    while(l <= r){
        int mid = l + r >> 1;
        if(check(mid)){
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    Out(ans);
    
    return 0;
}