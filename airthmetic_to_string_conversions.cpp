#include <iostream>
#include <string>
using namespace std;
int main(int argc, char **argv){
    /*
     *  These functions throw invalid_argument if no conversion could be performed and throw
out_of_range if the converted value is outside the range of the return type.
     */
        int val = -12;
        cout << "int val is: "  << std::to_string(val) ;
        unsigned int uval = 12;
        cout << "unsigned int uval: " << to_string(uval) ;
        long lval = 12L;
        cout << "long lval: " << to_string(lval);
        unsigned long ulval = 12uL;
        cout << "unsigned long uval: " << to_string(ulval);
        long long llval = 12ll;
        cout << "long long llval: " << to_string(llval);
        unsigned long long ullval=12ull;
        cout << "unsigned long long: " << to_string(ullval);
        float fval = 12.0f;
        cout << "float fval: " << to_string(fval);
        double dval = 12.0l;
        cout << "double dval: " << to_string(dval);
        long double ldval = 12.0;
        cout << "long double ldval: " << to_string(ldval);

        
        return 0;

}
