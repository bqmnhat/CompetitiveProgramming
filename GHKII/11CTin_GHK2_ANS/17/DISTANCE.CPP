#include<bits/stdc++.h>
using namespace std;
ifstream fin("DISTANCE.INP");
ofstream fout("DISTANCE.OUT");
typedef long double ld;

class Point{
public:
    int x, y;
    void getCoordinates(){
        fin >> x >> y;
    }
};

class Vec{
public:
    int x, y;
    void buildVector(Point a, Point b){
        x = b.x - a.x;
        y = b.y - a.y;
    }
    ld dot(Vec n){
        return x * n.x + y * n.y;
    }
    ld cross(Vec n){
        return x * n.y - y * n.x;
    }
};

Point k, a[1001];
int n, closestPointIndex, adjacent_closest1_index, adjacent_closest2_index;

ld getDistance(Point m, Point n){
    ld dx = n.x - m.x;
    ld dy = n.y - m.y;
    return sqrt(dx*dx + dy*dy);
}

ld disToSegment(Point x, Point m, Point n){
    Vec mn, mx, nx;
    mn.buildVector(m, n);
    mx.buildVector(m, x);
    nx.buildVector(n, x);

    if(mx.dot(mn) <= 0)
        return getDistance(m, x);
    else if(nx.dot(mn) >= 0)
        return getDistance(n, x);
    else
        return (abs(mn.cross(mx)) / getDistance(m, n));

}


int main(){
    fin >> n;
    k.getCoordinates();
    ld minDistance = 1000, currentDistance;
    for(int i = 0 ;i < n; i++){
        a[i].getCoordinates();
        currentDistance = getDistance(a[i], k);
        if(minDistance > currentDistance){
            minDistance = currentDistance;
            closestPointIndex = i;
        }
    }

    if(closestPointIndex == n-1){
        adjacent_closest1_index = closestPointIndex-1;
        adjacent_closest2_index = 0;
    }
    else if(closestPointIndex == 0){
        adjacent_closest1_index = n-1;
        adjacent_closest2_index = closestPointIndex+1;
    }
    else{
        adjacent_closest1_index = closestPointIndex-1;
        adjacent_closest2_index = closestPointIndex+1;
    }

    fout << setprecision(5)
         << min(disToSegment(k, a[closestPointIndex], a[adjacent_closest1_index]),
                disToSegment(k, a[closestPointIndex], a[adjacent_closest2_index]));

    return 0;
}
