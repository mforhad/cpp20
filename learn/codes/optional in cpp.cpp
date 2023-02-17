#include <iostream>
#include <optional>

/*
* std::optional is a std template that encapsulate a value that might 
* or might not exist.
* it is defined in the <optional> header.
* the ideal used case is the return type of a function where there 
* might or might not be any return value.
* it is an object that support dereferencing * and ->
*/
std::optional<std::string> getIntToString(int intVal) {
    if (intVal < 10)
        return std::optional<std::string> ("Less than ten.");
    else if (intVal == 10)
        return "Ten.";
    else if (intVal >= 11 && intVal <= 20)
        return std::make_optional<std::string> ("Between eleven and twenty.");
    else
        return std::nullopt;        
}

int main() {
    std::cout << getIntToString(5).value() << std::endl;
    std::cout << getIntToString(13).value() << std::endl;
    std::cout << getIntToString(10).value() << std::endl;
    std::cout << getIntToString(10)->size() << std::endl;
    std::cout << getIntToString(22).value() << std::endl;
    return 0;
}

// output
// Less than ten.
// Between eleven and twenty.
// Ten.
// 4
// terminate called after throwing an instance of 'std::bad_optional_access'
//   what():  bad optional access
  
