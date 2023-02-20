<center>

# C++ Programming
## Problems and Solutions

</center>

## Problem 1
### a) Answer: 1
Static typing in C++ means that the types of expressions are checked at compile-time. This means that the compiler checks the type compatibility of expressions during compilation, which helps catch type-related errors early.

### b) Answer: 3
The C++ preprocessor is a tool that performs text replacement in C++ source code before it is compiled. It is used to modify the source code, include header files, define constants, and perform other operations that are not part of the C++ language.

### c) Answer: 1
A build system like CMake simplifies the compilation of project sources and its dependencies by automating the build process. It generates platform-specific build scripts, which can be used to build the project. CMake can also be used to create reproducible, platform-independent builds.

### d) Answer: 2
A typical C++ compiler translates and optimizes valid C++ source code to platform-specific machine code. It also checks the syntax of the source code and performs static analysis to detect bugs and other issues.

### e) Answer: 3
The linker is responsible for combining the compiled object files into a single executable or shared library. As it does so, it resolves any references to external symbols, which are functions or variables that are defined in one translation unit and used in another. The linker ensures that the symbol addresses are properly linked so that the program can execute correctly.

### f) Answer: 1
Some ODR violations may not be caught by either the compiler or linker. However, both the compiler and linker can catch some ODR violations. Therefore, neither the compiler alone nor the linker alone can catch all ODR violations.

## Problem 2
### a) Answer: CPP supports so many programming paradigms that developers can use during writing programs,
- Imperative/Procedural programming: This paradigm involves specifying a sequence of commands to be executed by the computer, with an emphasis on how the program does things rather than what it does.
- Object-oriented programming (OOP): This paradigm involves organizing code into objects, which can contain data and functions that operate on that data. OOP emphasizes encapsulation, inheritance, and polymorphism.
- Functional programming: This paradigm involves writing code as a series of functions that take input and produce output without modifying state or causing side effects. It emphasizes immutability and referential transparency.
- Generic programming: This paradigm involves writing code that works with a variety of types, rather than being tied to a specific type. C++ supports generic programming through templates.
- Event-driven programming: This paradigm involves responding to user or system events, such as button clicks or network messages, by triggering functions or other code in response. C++ supports event-driven programming through libraries and frameworks.
- Concurrent programming: This paradigm involves writing code that runs in parallel with other code, often on different threads or processes. C++ supports concurrent programming through multithreading and other mechanisms.
- Meta-programming: This paradigm involves writing code that manipulates or generates other code, often at compile-time rather than run-time. C++ supports meta-programming through template metaprogramming and other techniques.
### b) Answer: Here is the one-line example of each,

```
extern int x; // declaration of x
int x; // definition of x
x = 20; // initialization of x
```
The complete program is as follows
```
#include <iostream>
#include <concepts>


extern int x; // declaration of x

int main() {
    int x; // definition of x
    x = 20; // initialization of x

    std::cout<<x<<std::endl;
    return 0;
}
```
