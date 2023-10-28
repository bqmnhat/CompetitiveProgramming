#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;
typedef long long ll;
ifstream fi;
ofstream fo;
void SizeCal(double G, double Y, double &m, double &n) {
    double del = (((G/2)+2)*((G/2)+2) - 4*(G+Y));
    if (del > 0) {
        n = ((G/2+2) + sqrt(del))/2;
        m = ((G/2+2) - sqrt(del))/2;
    }
    else if (del == 0) {
        n = (G/2 + 2)/2;
        m = n;
    }
    else {
        m = -1;
        n = -1;
    }
}

int main()
{
    double G,Y,m,n;
    fi.open("BRICKS.INP");
    fo.open("BRICKS.OUT");
    fi >> G >> Y;
    SizeCal(G,Y,m,n);
    fo << setprecision(0) << fixed << m << " " << n;
    return 0;
}
