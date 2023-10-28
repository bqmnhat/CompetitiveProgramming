#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n;
    double k,R = 0.0;
    ifstream fi;
    ofstream fo;
    fi.open("BAI5.INP");
    fo.open("BAI5.OUT");
    fi >> n >> k;
    for (int i = 1; i<=n; i++) {
        if (i%2 != 0) {
            R = R + k;
        }
        else {
            R = (R*k)/(R+k);
        }
    }
    fo << R;
    fi.close();
    fo.close();
    return 0;
}
