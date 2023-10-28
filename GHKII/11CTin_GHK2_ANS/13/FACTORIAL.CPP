#include <bits/stdc++.h>
using namespace std;

long long fact(long long k){
    if (k>0) return k*fact(k-1);
    else return 1;
}

int noDigits(long long k){
    int d=0;
    while (k>0){
        d++;
        k/=10;
    }
    return d;
}

int main(){
    freopen("FACTORIAL.INP","r",stdin);
    freopen("FACTORIAL.OUT","w",stdout);
    long long a = 0,b = 0;
    int m,n;
    cin >> m >> n;
    while (noDigits(fact(a))<m)
        a++;

    while (noDigits(fact(b))<=n)
        b++;
    if(noDigits(fact(b))>n) b--;
    if (noDigits(fact(a))>n || noDigits(fact(b))>n)
        cout << a << " " << a-1;
    else cout << a << " " << b;


    return 0;

}
