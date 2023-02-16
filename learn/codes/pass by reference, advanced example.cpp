#include <iostream>

int globalVar1{0};
int globalVar2{0};

// foo() returns the reference of the globalVar1 or globalVar2 based on conditionalParam
int& foo(unsigned conditionalParam) {
    if (conditionalParam == 1)
        return globalVar1;
    else
        return globalVar2;
}

int main() {
    std::cout << "Before Function call" << std::endl;
    std::cout << "Global var 1 = " << globalVar1 << std::endl;
    std::cout << "Global var 2 = " << globalVar2 << std::endl;
    
    foo(1) = 100; // modifies the value of globalVar1
    foo(2) = 200; // modifies the value of globalVar2

    std::cout << "After Function call" << std::endl;
    std::cout << "Global var 1 = " << globalVar1 << std::endl;
    std::cout << "Global var 2 = " << globalVar2 << std::endl;

    return 0;
}


// ######### Output ##########
// Before Function call
// Global var 1 = 0
// Global var 2 = 0
// After Function call
// Global var 1 = 100
// Global var 2 = 200