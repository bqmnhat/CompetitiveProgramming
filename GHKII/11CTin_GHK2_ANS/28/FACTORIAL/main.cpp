#include <bits/stdc++.h>
using namespace std;
void gt(int n);
 int main(){
    int n;
    cin >> n;
    cout << gt(n);
 }
    void gt(int n){
        int A[500000],i,j,m=1;
        long long r=0,q;
        A[0] = 1;
        for(i=2;i<=n;i++){
        for(j=0;j<m;j++){
        q =r ;
        r =(A[j]*i+r)/10;
        A[j] = (A[j]*i+q)%10;
    }
        while (r>0){
            A[m] = r%10;
            m++;
            r/=10;
        }
        }
    for (i = m -1;i>=0;i--) cout >> (A[i]);
    }
