#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


void ReadAndWritingFiles() {
    /// read

    //ifstream myStream("test.txt");
    //ifstream myStream;

    string filename = "tes.in";
    ifstream myStream(filename.c_str());

    myStream.open("te.txt");
    if (!myStream.is_open()) {
        cout << "fail to open the file";
    }
    int INT;
    myStream >> INT;


    /// writer
    ofstream of;
    of.open("out.io");
    of << "haha";
}


void streamManilulator() {
    /// endl as a manilulator

    /// setw
    /// left is default
    //cout << '[' << left << setw(12) << "hello" << ']' << endl;
    //cout << '[' << setw(12) << right << "hello" << ']' << endl;

    /// setfill
    cout << setfill('0') << setw(12) << "1234" << endl;
    cout << setw(12) << "1234" << endl;
    cout << setfill(' ') << setw(12) << "1234" << endl;

    cout << boolalpha << true << endl;

    cout << dec << 10 << endl;//10
    cout << hex << 10 << endl;//16
    cout << oct << 10 << endl;//8

    /// skip whitespace
    int a;
    cin >> ws >> a;// ????
}

void readfile(ifstream& input) {
    // while(true) {
    //     int vali, valj;
    //     input >> vali >> valj;
    //     if (input.fail()) {
    //         break;
    //     } else {
    //         /// .......
    //     }
    // }

    int a, b;
    while (input >> a >> b) {
        /// ....
    }
}

void getlineWrong() {
    // int n;
    // cin >> n;
    // string s;
    // getline(cin, s);
    /// fail, as \n is left int the buffer

    int n;
    cin >> n;
    cin.ignore();
    string s;
    getline(cin, s);
}

int getInteger() {
    while (true) {

        string line;
        getline(cin, line);
        stringstream oss;
        oss << line;

        int res;
        char trash;
        if (oss >> res && !(oss >> trash)) {
            return res;
        } else {
            cout << "IVALID INPUT" << endl;
            cout << "try next:";
        }
    }
}

bool HasHexLetters() {
    int n;
    n = getInteger();
    stringstream oss;
    oss << hex << n;
    string res = oss.str();
    oss.clear();
    oss << res;
    int num;
    char alpha;
    oss >> dec >> num;
    if (oss >> alpha)
        return true;
    else
        return false;
}

int main()
{
    // string s;
    // cin >>s;
    cout << boolalpha << HasHexLetters();
    return 0;
}
