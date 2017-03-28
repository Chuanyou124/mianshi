#include <iostream>

using namespace std;
int main()
{
    int *p = new int(3);
    const int *pt = p; // the memory pointed by pt is constant
    int * const px = p; // px itself is constant
    cout << *p << endl;
    cout << *pt << endl;
    cout << *px << endl;
    return 0;
}
