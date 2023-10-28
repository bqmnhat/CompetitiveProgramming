#include <iostream>

using namespace std;
class LopA {
    private: int x,y;
    public:
        int a,b;
        void nhap() {
            cin >> a >> b;
        }
};

class LopB : public LopA{
    public:
        void nhap() {
            cin >> a >> b;
            cout << "LopB";
        }
};

int main()
{
    LopB objLopB;
    objLopB.LopA->nhap();
    return 0;
}
