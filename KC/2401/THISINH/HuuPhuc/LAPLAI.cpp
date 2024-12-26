#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("LAPLAI.INP","r",stdin);
    freopen("LAPLAI.INP","w",stdout);

    int T;cin>>T;
    while(T--){
        int n;cin>>n;
        int a[n];
        int dem=1;
        if(n%2!=0){
            a[(n+1)/2-1]=dem;
            dem+=1;
            if(((n+1)/2-1)%2==0){
                a[((n+1)/4 -1)]=dem;
                dem+=1;
            }
        }
    }
    return 0;
}
