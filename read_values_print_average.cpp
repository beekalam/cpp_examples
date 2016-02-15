#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
int main(int argc, char **argv){
        vector<double> values;
        cout << "Enter values separated by one or more spaces. Enter ctrl+z "
               "to  end:\n";
        values.insert(begin(values), istream_iterator<double>(cin),
                                     istream_iterator<double>());
        cout << "The average is " << 
             (accumulate(begin(values), end(values),0.0)/ values.size()) 
             << endl;
        return 0;

}
