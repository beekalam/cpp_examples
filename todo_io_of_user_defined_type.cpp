#include <iostream>
#include <ios>
#include <string>
using namespace std;
struct Entry{
    string name;
    int number;
};
ostream& operator<<(ostream& os, const Entry& e){
    return os << "{\n" <<e.name <<"\"," << e.number <<"}";
}

istream& operator>>(istream& is,Entry& e){
    char c,c2;
    if(is>>c && c=='{' && is>>c2 && c2=='"'){ //start with {"
        string name;
        while(is.get(c) && c!='"')   //anything before a " is part of name
            name += c;

        if(is>>c && c == ','){
            int number = 0;
            if(is >> number >>c && c=='}'){ //read the number and }
              e = {name,number};
              return is;
        }
      }
    }
    is.setf(ios_base::failbit);   //register the failure in the stream
    return is;
}
int main(int argc, char **argv){
        for(Entry ee: cin >> ee;)
           cout << ee << '\n'; 
        return 0;

}
