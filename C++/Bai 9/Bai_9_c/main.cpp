#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

int main()
{
    /*string s;
    ifstream fi;
    ofstream fo;
    fi.open("BAI9C.INP");
    fo.open("BAI9C.OUT");
    fi >> s;
    int x,y,sum = 0;
    string s1,s2;
    for (int i = 1; i <= s.length()-1; i++) {
        //s1 = const_cast<char*>(s.substr(i,1).c_str());
        //s2 = const_cast<char*>(s.substr(i-1,1).c_str());
        s1 = s.substr(i,1);
        s2 = s.substr(i-1,1);
        istringstream(s1) >> x;
        istringstream(s2) >> y;
        sum += abs(x - y);
    }
    fo << sum;
    return 0; */
    long long n;
    ifstream fi;
    ofstream fo;
    fi.open("BAI9C.INP");
    fo.open("BAI9C.OUT");
    fi >> n;
    int sum = 0;
    while (n>9) {
        sum = sum + (int)abs(n%10 - ((n%100)/10));
        n = n/10;
    }
    fo << sum;
    return 0;
}
