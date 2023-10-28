#include <iostream>

using namespace std;

int main()
{
    int a = 0;
    for (int i=1; i<=100000; i++) {
        for (int j=1; j<=100000; j++) {
            a++;
        }
    }
    return 0;
}
