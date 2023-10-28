#include <iostream>
#include <fstream>
using namespace std;
typedef long long ll;
ifstream fi;
ofstream fo;
int m,n;

int CountBlue(int m, int n) {
    int blue = 0;
    blue = (int(m/5)*n) + (int(n/5)*m) - (int(m/5) * int(n/5));
    return blue;
}

int CountGreen(int m,int n) {
    int green = 0, i = 3;
    while (i <= m) {
        for (int j = 1; j <= n; j++){
            if (i*j % 5 != 0)
                green = green + 1;
        }
        i = i + 3;
    }
    i = 3;
    while (i <= n) {
        for (int j = 1; j <= m; j++){
            if ((i*j % 5 != 0) && (j % 3 !=0))
                green = green + 1;
        }
        i = i + 3;
    }
    return green;
}

int CountRed(int m, int n) {
    int red = 0, i = 2;
    while (i <= m) {
        for (int j = 1; j <= n; j++){
            if ((i*j % 5 != 0) && (i*j % 3 != 0))
                red = red + 1;
        }
        i = i + 2;
    }
    i = 2;
    while (i <= n) {
        for (int j = 1; j <= m; j++){
            if ((i*j % 5 != 0)&& (i*j % 3 != 0) && (j % 2 != 0))
                red = red + 1;
        }
        i = i + 2;
    }
    return red;
}

int main()
{
    fi.open("COLORING.INP");
    fo.open("COLORING.OUT");
    fi >> m >> n;
    int blue = CountBlue(m,n);
    int green = CountGreen(m,n);
    int red = CountRed(m,n);
    fo << red << '\n' << green << '\n' << blue << '\n' << (m*n) - red - green - blue;
    return 0;
}
