#include <bits/stdc++.h>
using namespace std;
const int N=100100;
int n,ans=0;
string a[N];

int main() {
    cin>>n;
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<n;i++) {
        int minLen=a[i].length(),maxLen=a[i].length();
        for(int j=i;j<n;j++) {
            minLen=min(minLen,(int)a[j].length());
            maxLen=max(maxLen,(int)a[j].length());
            if(maxLen-minLen<=1)
                ans=max(ans,j-i+1);
            else
                break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
