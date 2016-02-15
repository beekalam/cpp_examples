#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
using namespace std;
int main(int argc, char **argv){
        
        return 0;

}
/*
 * weak_ptr<T> Pointers
A weak_ptr<T> object can only be created from a shared_ptr<T> object. weak_ptr<T> pointers are typically used as class members that store an address of another instance of the same class, when objects of the class are created in the free store. Using a shared_ptr<T> member to point to another object of the same type in such circumstances has the potential for creating a reference cycle, which would prevent objects of the class type from being deleted from the free store automatically. This is not a common situation, but it is possible, as Figure 1-4 shows.
 * Deleting all the smart pointers in the array in Figure 1-4 or resetting them to nullptr does not delete the memory for the objects to which they point. There is still a shared_ptr<X> object containing the address of every object. There are no external pointers remaining that can access these objects so they cannot be deleted. The problem can be avoided if the objects used weak_ptr<X> members to refer to other objects. These would not prevent the objects from being destroyed when the external pointers in the array are destroyed or reset.
You can create a weak_ptr<T> object like this:

              auto pData = std::make_shared<X>();     // Create a shared pointer to an object of type X
            

              std::weak_ptr<X> pwData {pData};        // Create a weak pointer from shared pointer
            

              std::weak_ptr<X> pwData2 {pwData};      // Create a weak pointer from another
            
Thus you can create a weak_ptr<T> from a shared_ptr<T> or from an existing weak_ptr<T>. You can’t do very much with a weak pointer – you can’t dereference it to access the object it points to, for example. You can do two things with a weak_ptr<T> object:

    You can test whether the object it points to still exists, which means there’s a shared_ptr<T> still around that points to it.
    You can create a shared_ptr<T> object from a weak_ptr<T> object.

Here’s how you can test for the existence of the object that a weak pointer references:

              if(pwData.expired())
            
   std::cout << "Object no longer exists.\n";
The expired() function for the pwData object returns true if the object no longer exists. You can create a shared pointer from a weak pointer like this:

              std::shared_ptr<X> pNew {pwData.lock()};
            
The lock() function locks the object if it exists by returning a new shared_ptr<X> object that initializes pNew. If the object does not exist, the lock() function will return a shared_ptr<X> object containing nullptr. You can test the result in an if statement:

              if(pNew)
            
   std::cout << "Shared pointer to object created.\n";

              else
            
   std::cout << "Object no longer exists.\n";
Working with weak_ptr<T> pointers is outside the scope of this book so I won’t be delving into these any further. I’ll be exploring the implications and merits of storing smart pointers in containers in Chapter 3.
 */
