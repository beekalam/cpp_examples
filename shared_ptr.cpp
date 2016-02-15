#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
using namespace std;
int main(int argc, char **argv){
        shared_ptr<double> pdata {new double{999.0}};
        *pdata = 888.0;
        cout << *pdata << endl;
        cout << "--------------make_shared ---------------- " << endl;
        auto pdata2 = make_shared<double>(999.0); // Points to a double variable
        cout << "--------------initialize a shared_ptr<T> with another--- " << endl;
        shared_ptr<double> pdata3 {pdata};
        cout << "pdata3: " << *pdata3 << endl;
        cout << "-------------assign one shared_ptr<T> to another --------"<<endl;
        shared_ptr<double> pdata4{ new double{ 999.0 } };
        shared_ptr<double> pdata5;    //pointer contains nullptr
        pdata5 = pdata4;              // copy pointer - both point to the same variable
        cout <<"*pdata4: " << *pdata4 << endl; 
        cout <<"*pdata5: " << *pdata5 << endl;
        cout << "-------------reseting shared_ptr<T> objects -------------" << endl;
        auto pname = make_shared<string>("Charles Dickens"); //points to a string object
        // pname.reset() is the same as the following
        pname = nullptr;                           //reset pname to nullptr
        cout<<"-----------check whether a shared_ptr<T> object has any duplicates" << endl;
        auto pname2 = make_shared<string>("Charles Dickens");
        if(pname.unique())
            cout << "There is only one..." << endl;
        else
            cout << "there is more than one" << endl;

        return 0;

}
/*
 * Using shared_ptr<T> Pointers
You can define a shared_ptr<T> object like this:

              std::shared_ptr<double> pdata {new double{999.0}};
            
You can also dereference a shared pointer to access what it points to or to change the value stored at the address:

              *pdata = 8888.0;
            

              std::cout << *pdata << std::endl;      // Outputs 8888.0
            

              *pdata = 8889.0;
            

              std::cout << *pdata << std::endl;      // Outputs 8889.0
            
The definition of pdata involves one allocation of heap memory for the double variable, and another allocation relating to the smart pointer object for the control block that it uses to record the number of copies of the smart pointer. Allocating heap memory is relatively expensive on time. You can make the process more efficient by using the make_shared<T>() function that is defined in the memory header to create a smart pointer of type shared_ptr<T>:

              auto pdata = std::make_shared<double>(999.0);  // Points to a double variable
            
The type of variable to be created in the free store is specified between the angled brackets. The argument between the parentheses following the function name is used to initialize the double variable it creates. In general, there can be any number of arguments to the make_shared<T>() function, the actual number depending of the type of object being created. When you are using make_shared<T>() to create objects in the free store, there can be two or more arguments separated by commas if the T constructor requires them. The auto keyword causes the type for pdata to be deduced automatically from the object returned by make_shared<T>() so it will be shared_ptr<double>. Don’t forget though – you should not use an initializer list when you specify a type as auto because the type will be deduced to be std::initializer_list.
You can initialize a shared_ptr<T> with another when you define it:

              std::shared_ptr<double> pdata2 {pdata};
            
pdata2 points to the same variable as pdata, which will cause the reference count to be incremented. You can also assign one shared_ptr<T> to another:

              std::shared_ptr<double> pdata{ new double{ 999.0 } };
            

              std::shared_ptr<double> pdata2;        // Pointer contains nullptr
            

              pdata2 = pdata;                        // Copy pointer - both point to the same variable
            

              std::cout << *pdata << std::endl;      // Outputs 999.0
            
Of course, copying pdata increases the reference count. Both pointers have to be reset or destroyed for the memory occupied by the double variable to be released. You can’t use a shared_ptr<T> to store the address of an array created in the free store by default. However, you can store the address of an array<T> or vector<T> container object that you create in the free store.
Note
It is possible to create a shared_ptr<T> object that points to an array. This involves supplying a definition for a deleter function that the smart pointer is to use to release the heap memory for the array. The details of how you do this are outside the scope of this book.
In a similar way to that for a unique_ptr<T>, you can get a raw pointer to the object to which a shared_ptr<T> object points by calling its get() member. For pdata as defined in the previous section, you could write:

              auto pvalue = pdata.get();             // pvalue is type double* and points to 999.0
            
You only need to do this when it’s essential to use the raw pointer.
Caution
Duplicates of a shared_ptr<T> object should only be created by the copy constructor or the copy assignment operator. Creating a shared_ptr<T> using the raw pointer returned by get() for a different pointer will result in undefined behavior, which in most cases means a program crash.
**********************************************************************
Resetting shared_ptr<T> Objects
If you assign nullptr to a shared_ptr<T> object the address stored will be replaced by nullptr, which has the effect of reducing the reference count for pointers to the object by 1. For example:

                auto pname = std::make_shared<std::string>("Charles Dickens");  // Points to a string object
              

                // ... lots of other stuff happening...
              

                pname = nullptr;                                                // Reset pname to nullptr
              
This creates a string object initialized with "Charles Dickens" in the free store and creates a shared pointer containing its address. Eventually, assigning nullptr to pname replaces the address stored with nullptr. Of course, any other shared_ptr<T> objects that hold the address of the string object will continue to exist – just the reference count will have been decremented.
You can obtain the same result by calling reset() for the shared_ptr<T> object with no argument value:

                pname.reset();                                                  // Reset to nullptr
              
You can also pass a raw pointer to reset() to change what the shared pointer points to. For example:

                pname.reset(new std::string{"Jane Austen"});                    // pname points to new string
              
The argument to reset() must be an address of the same type as was originally stored in the smart pointer, or must be implicitly convertible to that type.
**********************************************************************
Comparing and Checking shared_ptr<T> Objects
You can compare the address contained in one shared_ptr<T> object with another, or with nullptr using any of the comparison operators. The most useful are comparisons for equality or inequality, which tell you whether or not two pointers point to the same object. Given two shared_ptr<T> objects, pA and pB, that point to the same type, T, you can compare them like this:

                if((pA == pB) && (pA != nullptr))
              
  std::cout << " Both pointers point to the same object.\n";
The pointers could both be nullptr and be equal so a simple comparison is not sufficient to establish that they both point to the same object. Like a unique_ptr<T>, a shared_ptr<T> object can be implicitly converted to type bool so you could write the statement as:

                if(pA && (pA == pB))
              
  std::cout << " Both pointers point to the same object.\n";
You can also check whether a shared_ptr<T> object has any duplicates:

                auto pname = std::make_shared<std::string>("Charles Dickens");
              

                if(pname.unique())
              
  std::cout << there is only one..." << std::endl;

                else
              
  std::cout << there is more than one..." << std::endl;
The unique() function member returns true if the recorded number of instances of the object is 1, and false otherwise. You can also determine how many instances there are:

                if(pname.unique())
              
  std::cout << there is only one..." << std::endl;

                else
              
  std::cout << there are " << pname.use_count() << " instances." << std::endl;
The use_count() member return the number of instances of the object for which it was called. It returns 0 if the share_ptr<T> object contains nullptr.
 */
