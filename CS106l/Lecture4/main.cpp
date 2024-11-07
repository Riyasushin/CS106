#include <iostream>
#include <string>
#include<sstream>
using namespace std;

/// special preprocessor values
string getInformation() {
    stringstream result;
    result << "The program was compiled on " << __DATE__ << " at time " << __TIME__;
    result <<"\n" <<" , which is the file " <<__FILE__ << " and line " << __LINE__ << endl;
    return result.str();
}

/// string manipulation functions
#define PRINTOUT(n) cout << #n << " has the value " << n <<endl // NO; HERE!!

void tryundef() {
    #define MYINT 1223
    int n = MYINT;
    #undef MYINT
    int MYINT = 42;
    PRINTOUT(n);
    PRINTOUT(MYINT);
}


enum Color {
#define DEFINE_COLOR(color, opposite) color,
#include "color.h"
#undef DEFINE_COLOR

};
string ColorToString(Color c) {
    switch (c) {
#define DEFINE_COLOR(color, opposite) case color: return #color;
#include "color.h"
#undef DEFINE_COLOR
    default: return "unknow";
    }
}
Color OppositeColor(Color c) {
    switch (c) {
#define DEFINE_COLOR(color, opposite) case color: return opposite;
#include "color.h"
#undef DEFINE_COLOR
    default: return c;
    }
}

int main()
{
    cout << getInformation();

    int n = 42;
    PRINTOUT(n);

    tryundef();

    cout << ColorToString(OppositeColor(Blue));

    return 0;
}
