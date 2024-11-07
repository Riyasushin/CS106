#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream name("test.txt");
    if (!name.is_open()) {
        cerr << "fail to open test.txt" <<endl;
        return -1;
    }

    string key, val;
    while (getline(name, key) && getline(name, val)) {
        // ...
    }

    return 0;
}
