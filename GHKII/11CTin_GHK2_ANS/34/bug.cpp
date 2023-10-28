#include <bits/stdc++.h>
using namespace std;

struct Cor{
    int x;
    int y;
};

int main()
{
    int n, sumx=0, sumy=0; Cor a[1000000];
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i].x >> a[i].y;
        sumx+=a[i].x, sumy+=a[i].y;
    }
    int avgx=sumx/n, avgy=sumy/n;

}
