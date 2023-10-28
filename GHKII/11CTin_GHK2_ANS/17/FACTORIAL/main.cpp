#include<bits/stdc++.h>
using namespace std;
ifstream fin("FACTORIAL.INP");
ofstream fout("FACTORIAL.OUT");
int m, n;
int main(){
    fin >> m >> n;
    int sum1 = 0;
    int i = 1;
    while(sum1 < m){
        int value = log10(i);
        sum1 += value;
        i++;
    }
    int sum2 = 0;
    i = 1;
    while(sum2 > n){
        int value = log10(i);
        sum2 += value;
        i++;
    }
    fout << sum1 << sum2;
    return 0;
}
