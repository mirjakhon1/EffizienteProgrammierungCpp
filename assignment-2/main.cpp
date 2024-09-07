#include "iostream"
#include "test11.h"
#include "vec.h"

using namespace std;
using namespace my;

int main()
{
    test_Vec3f<double, 3>();
    // Vec<float, 2> myVec(21.0f, 13.0f);

    // auto negatedVec = myVec;
    // cout << "First element " << myVec[0] << endl;
    // cout << "Second element " << myVec[1] << endl;
    // cout << "-----" << endl;
    // cout << "First element " << negatedVec[0] << endl;
    // cout << "Second element " << negatedVec[1] << endl;
    // cout << "Are equal: " << (negatedVec == myVec) << endl; 

    return 0;
}