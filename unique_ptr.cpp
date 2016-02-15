#include <iostream>
#include <string>
#include <memory>
using namespace std;
int main(int argc, char **argv){
        unique_ptr<string> pname { new string{"Algernon"}};
        cout <<"*panme: " << *pname << endl;
        //auto pname2 = make_unique<string>("Algernon");
        //auto pstr = make_unique<string>(6, '*');

        size_t len{10};
        unique_ptr<int[]> pnumbers{new int[len]};
        //auto pnumbers2 = make_unique<int []>(len);
        for(size_t i{}; i < len; ++i)
          pnumbers[i] = i *i;
        for( size_t i{}; i < len; ++i)
            cout<< pnumbers[i] << endl;


        return 0;

}
/*
 * Using unique_ptr<T> Pointers
A unique_ptr<T> object stores an address uniquely so the object to which it
points is owned exclusively by the unique_ptr<T> object. When the unique_ptr<T>
object is destroyed, the object to which it points is destroyed, too. This type
of smart pointer applies when you don’t need to have multiple smart pointers
and you want to ensure a single point of ownership. When an object is owned by
a unique_ptr<T>, you can provide access to the object by making a raw pointer
available. Here’s how you can create a unique_ptr<T> using a constructor:

              std::unique_ptr<std::string> pname {new std::string {"Algernon"}};
            
The string object that is created on the heap is passed to the
unique_ptr<string> constructor. The default constructor will create a
unique_ptr<T> with nullptr as the internal raw pointer.
A much better way to create unique_ptr<T> objects is to use the
make_unique<T>() function template that is defined in the memory header:

              auto pname = std::make_unique<std::string>("Algernon");
            
The function create the string object on the heap by passing the argument to
the class constructor and creates and returns the unique pointer to it. You
supply as many arguments to the make_unique<T>() function as the T constructor
requires. Here’s an example:

              auto pstr = std::make_unique<std::string>(6, '*');
            
There are two arguments that will be passed to the string constructor so the
object that is created contains "******".
You can dereference the pointer to access the object, just like a raw pointer:

              std::cout << *pname << std::endl;      // Outputs Algernon
            
You can create a unique_ptr<T> that points to an array. For example:

              size_t len{10};
            

              std::unique_ptr<int[]> pnumbers {new int[len]};th
            
This creates a unique_ptr object pointing to the array of len elements that is
created in the free store. You could achieve the same result by calling
make_unique<T>():

              auto pnumbers = std::make_unique<int[]>(len);
            
This also creates a pointer to the array of len elements that is created on the
heap. You can use an index with the unique_ptr variable to access the array
elements. Here’s how you can change the values:

              for(size_t i{} ; i < len ; ++i)
            
  pnumbers[i] = i*i;
This sets the array elements to values that are the square of their index
positions. Of course, you can use the subscript operator to output the values:

              for(size_t i{} ; i < len ; ++i)
            
  std::cout << pnumbers[i] << std::endl;
You cannot pass a unique_ptr<T> object to a function by value because it cannot
be copied. You must use a reference parameter in a function to allow a
unique_ptr<T> object as an argument. You can return a unique_ptr<T> from a
function because it will not be copied, but will be returned by an implicit
move operation.
You can only store unique_ptr<T> objects in a container by moving them there or
creating them in place because unique_ptr<T> objects cannot be copied. There
can never be two unique_ptr<T> objects containing the same address.
shared_ptr<T> objects don’t have this characteristic, so you use these whenever
you need multiple pointers to an object, or when you need to copy the contents
of a container that stores smart pointers; otherwise use unique_ptr<T> objects.
With a container that has unique_ptr<T> elements, you may need to make the raw
pointer to an object available. Here’s how you obtain a raw pointer from a
unique_ptr<T>:

              auto unique_p = std::make_unique<std::string>(6, '*');
            

              std::string pstr {unique_p.get()};
            
The get() function member returns the raw pointer that the unique_ptr<T>
contains. A typical circumstance when you would do this is to provide access to
an object when the smart pointer to it is encapsulated in a class object. You
can’t return the unique_ptr<T> because it cannot be copied.
 */

