#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    long long a,b,n,y;
    ifstream fi;
    ofstream fo;
    fi.open("BAI8.INP");
    fi >> a >> b >> n;
    for (y = n/b; y>=0; y--) {
        if ((n-(b*y))%a == 0){
            long long x = (n-(b*y))/a;
            fo.open("BAI8.OUT");
            fo << b*y + a*x;
            return 0;
        }
    }
    return 0;
}
