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
    long long tmp = n;
    while (tmp >= 0) {
        for (y = tmp/b; y>=0; y--) {
            if ((tmp-(b*y))%a == 0){
                long long x = (n-(b*y))/a;
                fo.open("BAI8.OUT");
                fo << b*y + a*x;
            }
        }
        tmp = tmp - 1;
    }
    return 0;
}
