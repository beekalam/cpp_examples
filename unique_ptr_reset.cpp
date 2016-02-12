#include <iostream>
#include <string>
#include <memory>
using namespace std;
int main(int argc, char **argv){
        //auto pname = std::make_unique<std::string>("Algernon");
        //pname.reset();   //Release 
        return 0;

}
/*
 * Resetting unique_ptr<T> Objects
The object to which a unique_ptr<T> object points is destroyed when the smart
pointer is destroyed. Calling reset() for a unique_ptr<T> object with no
argument destroys the object that is pointed to and replaces the raw pointer in
the unique_ptr<T> object with nullptr; this enables you to destroy the object
that is pointed to at any time. For example:

                auto pname = std::make_unique<std::string>("Algernon");
              

                ...
              

                pname.reset();                                   // Release memory for string object
              
You can pass the address of a new T object in the free store to reset(), and
the previous object that was pointed to will be destroyed and its address will
be replaced by that of the new object:

                pname.reset(new std::string{"Fred"});
              
This releases the memory for the original string that was pointed to by pname,
creates a new string object "Fred" in the free store, and stores its address in
pname.

Caution
You must not pass the address of a free store object to reset() that is
contained by a different unique_ptr<T> object, or create a new unique_ptr<T>
using an address that is already contained in another unique_ptr<T>. Such code
will probably compile, but your program will certainly crash. The destruction
of the first unique_ptr<T> will release the memory for the object that it
points to. The destruction of the second will result in an attempt to release
the memory that has already been released.

You can release the object that a unique_ptr<T> points to by calling release()
for the smart pointer. This sets the raw pointer contained in the unique_ptr<T>
to nullptr without releasing the memory for the original object. For example:

                auto up_name = std::make_unique<std::string>("Algernon");
              

                std::unique_ptr<std::string> up_new_name{up_name.release()};
              
The release() member of up_name returns the original raw pointer to the string
object containing "Algernon" so after executing the second statement, up_name
will contain nullptr, and up_new_name will point to the original "Algernon"
string object. The effect is to transfer ownership of the object in the free
store from one unique pointer to another.
You can interchange the objects owned by two unique_ptr<T> pointers:

                auto pn1 = std::make_unique<std::string>("Jack");
              

                auto pn2 = std::make_unique<std::string>("Jill");
              

                pn1.swap(pn2);
              
After executing the second statement here, pn1 will point to the string "Jill"
and pn2 will point to "Jack."
 */
