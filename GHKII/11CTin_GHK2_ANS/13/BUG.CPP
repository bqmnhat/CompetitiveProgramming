#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x;
    int y;
    void input(int x1,int y1){
        x = x1; y = y1;
    }
};


int main() {
    freopen("BUG.INP","r",stdin);
    freopen("BUG.OUT","w",stdout);
    int n;
    cin >> n;
    Point bug[n];
    int xArr[n];
    int maxY = -INT_MAX;
    int minY = INT_MAX;

    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        bug[i].input(x,y);
        xArr[i] = x;
        maxY = max(maxY,bug[i].y);
        minY = min(minY,bug[i].y);
    }

    int line = (maxY+minY)/2;

    int tmp;
    for (int i=0;i<n;i++){
        for (int j = 0;j<n;j++){
            if (xArr[i]>xArr[j]){
                tmp = xArr[i];
                xArr[i]=xArr[j];
                xArr[j] =tmp;
            }
        }
    }
    tmp = xArr[0];
    int noSteps = abs(line-bug[0].y);
    for (int i = 1;i<n;i++){
        noSteps += abs(line-bug[i].y);
    }

    cout << noSteps;


}
