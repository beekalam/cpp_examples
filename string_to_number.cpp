#include <iostream>
#include <string>
using namespace std;
int main(int argc, char **argv){
     try {
        int val = stoi("12");
        cout << "val: " << val << endl;
        //todo: change the radix
//        cout << "val: " << stoi("12", nullptr, 2) << endl;
        long lval = stol("12");
        cout <<"lval: " << lval << endl;

        unsigned long ulval = stoul("12");
        cout << "ulval: " << ulval << endl;

        long long llval = stoll("12");
        cout << "llval: " << llval << endl;

        unsigned long long ullval = stoull("12");
        cout << "ullval: " << ullval << endl;

        float fval = stof("12.0");
        cout << "fval: " << fval << endl;

        double dval = stod("12.0");
        cout << "dval: " << dval << endl;

        long double ldval = stold("12.0");
        cout << "ldval: " << ldval << endl;

    }catch(...){
        cout << "eror occured";
    }
        return 0;

}
