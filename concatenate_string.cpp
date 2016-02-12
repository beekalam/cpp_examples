#include <iostream>
#include <string>
using namespace std;
string compose(const string& name, const string& domain){
    return name + '@' + domain;
}

int main(int argc, char **argv){
    auto addr = compose("dmr","bell-labs.com");  
    cout <<"\n" << addr << "\n";

        return 0;

}
