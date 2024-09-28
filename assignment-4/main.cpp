#include "my_vector.h"
#include "iostream"

#define CTOR std::cout << "CTOR" << std::endl;

using namespace std;

int main()
{
    my::my_vector<float> a(3, 10.0f);
    a.print();
    cout << a.at(1) << endl;
    cout << "Size: " << a.size() << endl;
    cout << "Capacity: " << a.capacity() << endl;
    return 0;
}

