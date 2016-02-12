#include <iostream>
#include <climits>
#include <cfloat>
using namespace std;
int main(int argc, char **argv){
    cout <<"max size of short int: " << SHRT_MAX << endl;
    cout <<"min size of short int: " << SHRT_MIN << endl;

    cout <<"max size of int: " << INT_MAX << endl;
    cout <<"min size of int: " << INT_MIN << endl;

    cout <<"max of long long: " << LLONG_MAX << endl;
    cout <<"min of long long: " << LLONG_MIN << endl;

    cout <<"the minimum positive value of  float: " << FLT_MIN << endl;
    cout <<"the minimum epsilon value of float: " << FLT_MIN << endl;
    cout <<"the maximum value of a float is " << FLT_MAX << endl;

     cout << "The minimum positive value of a double is "
 << DBL_MIN<< endl;
 cout << "The minimum epsilon value of a double is "
 << DBL_EPSILON << endl;
 cout << "The maximum value of a double is "
 << DBL_MAX << endl;

 // long double might not be defined on some systems
 cout << "The minimum positive value of a long double is "
 << LDBL_MIN<< endl;
 cout << "The minimum epsilon value of a long double is "
 << LDBL_EPSILON << endl;
 cout << "The maximum value of a long double is "
 << LDBL_MAX << endl;
    return 0;

}
