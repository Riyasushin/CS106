#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    const char* pointer_to_const; /// a telescope
    char const* pointer_to_const2;

    char* const const_pointer = 'c'; /// a laser
    // const_pointer = 'd'; // illegal

    const char* const ppp;
    return 0;
}
