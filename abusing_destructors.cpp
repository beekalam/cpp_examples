//taken from http://msoucy.me
#include <iostream>
using namespace std;

struct ProgramWrapper {
    ~ProgramWrapper() {
    	cout << "in destructor" << endl;
        cin.sync();
        cin.ignore();
    }
} wrapper;

int main() {
	cout << "in main" << endl;
    return 0;
}

/*
Abusing destructors

Destructors are called when a class (or struct) leaves scope.

This includes when the program is cleaning up after itself when it's exiting main.

#include <iostream>
using namespace std;

struct ProgramWrapper {
    ~ProgramWrapper() {
        cin.sync();cin.ignore();
    }
} wrapper;

int main() {
    return 0;
}
*/