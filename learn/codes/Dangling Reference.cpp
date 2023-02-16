#include <iostream>

int& getReference() {
    int localVar = 5;

    // Returning a reference to a local variable
    return localVar;
}

int main() {
    int& ref = getReference();
    // Using ref here is undefined behavior, because localVar of the function has been deallocated as the scope no longer exists
    std::cout << ref << std::endl;
    
    // Another example
    int localVar2 = 5;
    int& ref2 = localVar2;
    delete &localVar2; // Deallocating localVar2 while ref still refers to it
    // Using ref here is undefined behavior, because localVar2 has been deallocated
    std::cout << ref2 << std::endl;
    
    return 0;
}

// ############# Output ############
// prog.cc: In function 'int& getReference()':
// prog.cc:7:12: warning: reference to local variable 'localVar' returned [-Wreturn-local-addr]
//     7 |     return localVar;
//       |            ^~~~~~~~
// prog.cc:4:9: note: declared here
//     4 |     int localVar = 5;
//       |         ^~~~~~~~
// prog.cc: In function 'int main()':
// prog.cc:18:13: warning: 'void operator delete(void*, std::size_t)' called on unallocated object 'localVar2' [-Wfree-nonheap-object]
//    18 |     delete &localVar2; // Deallocating localVar2 while ref still refers to it
//       |             ^~~~~~~~~
// prog.cc:16:9: note: declared here
//    16 |     int localVar2 = 5;
//       |         ^~~~~~~~~